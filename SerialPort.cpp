#include "SerialPort.h"


bool SerialPort::InitSerialPort(const char* SerialName, int BaudRate, char parity, char databit, char stopbit, AccessMethod accessMethod, FlagsAndAttributes flagsAndAtrributes)
{
		switch (accessMethod)
		{
		case 0:
			if (flagsAndAtrributes == Synchronous)
			{
				this->spSettingInfo.serialName = SerialName;
				this->spSettingInfo.dwDesiredAccess = GENERIC_READ;
				this->spSettingInfo.dwFlagsAndAttributes = 0;
				break;
			}
			else
			{
				this->spSettingInfo.serialName = SerialName;
				this->spSettingInfo.dwDesiredAccess = GENERIC_READ;
				this->spSettingInfo.dwFlagsAndAttributes = FILE_FLAG_OVERLAPPED;
				break;
			};
		case 1:
			if (flagsAndAtrributes == Synchronous)
			{
				this->spSettingInfo.serialName = SerialName;
				this->spSettingInfo.dwDesiredAccess = GENERIC_WRITE;
				this->spSettingInfo.dwFlagsAndAttributes = 0;
				break;
			}
			else
			{
				this->spSettingInfo.serialName = SerialName;
				this->spSettingInfo.dwDesiredAccess = GENERIC_WRITE;
				this->spSettingInfo.dwFlagsAndAttributes = FILE_FLAG_OVERLAPPED;
				break;
			};
		case 2:
			if (flagsAndAtrributes == Synchronous)
			{
				this->spSettingInfo.serialName = SerialName;
				this->spSettingInfo.dwDesiredAccess = GENERIC_READ|GENERIC_WRITE;
				this->spSettingInfo.dwFlagsAndAttributes = 0;
				break;
			}
			else
			{
				this->spSettingInfo.serialName = SerialName;
				this->spSettingInfo.dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
				this->spSettingInfo.dwFlagsAndAttributes = FILE_FLAG_OVERLAPPED;
				break;
			};
		}
		this->hCom = CreateFileA(this->spSettingInfo.serialName, this->spSettingInfo.dwDesiredAccess, this->spSettingInfo.dwShareMode, this->spSettingInfo.lpSecurityAttributes, this->spSettingInfo.dwCreationDistribution, this->spSettingInfo.dwFlagsAndAttributes, this->spSettingInfo.hTemplateFile);
		if (hCom == INVALID_HANDLE_VALUE)
		{
			return false;
		}
		if(!SetupComm(hCom,1024,1024))//设定缓冲区为1KB
		{
			return false;
		}
		DCB dcb;
		GetCommState(hCom, &dcb);
		dcb.BaudRate = BaudRate;
		dcb.ByteSize = databit;
		switch (parity)
		{
		case 0:
			dcb.Parity = NOPARITY; //无校验
			break;
		case 1:
			dcb.Parity = ODDPARITY; //奇校验
			break;
		case 2:
			dcb.Parity = EVENPARITY; //偶校验
			break;
		case 3:
			dcb.Parity = MARKPARITY; //标记校验
			break;
		}
		switch (stopbit)
		{
		case 1:
			dcb.StopBits = ONESTOPBIT; //1位停止位
			break;
		case 2:
			dcb.StopBits = TWOSTOPBITS; //2位停止位
			break;
		case 3:
			dcb.StopBits = ONE5STOPBITS; //1.5位停止位
			break;
		}
		if (!SetCommState(hCom, &dcb))
		{
			return false;
		}
		//超时处理
		COMMTIMEOUTS TimeOuts;
		TimeOuts.ReadIntervalTimeout = 1000; //读间隔超时
		TimeOuts.ReadTotalTimeoutMultiplier = 500; //读时间系数
		TimeOuts.ReadTotalTimeoutConstant = 5000; //读时间常量
		TimeOuts.WriteTotalTimeoutMultiplier = 500; // 写时间系数
		TimeOuts.WriteTotalTimeoutConstant = 2000; //写时间常量
		SetCommTimeouts(hCom, &TimeOuts);

		PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);//清空串口缓冲区
		return true;
		
}

bool SerialPort::unInitSerialPort()
{
	if (CloseHandle(hCom))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SerialPort::WriteToPort(const void * buf,int len)
{
	if (this->spSettingInfo.dwFlagsAndAttributes==Synchronous)
	{
		DWORD dwBytesWrite = len; //成功写入的数据字节数
		BOOL bWriteStat = WriteFile(hCom, //串口句柄
			buf, //数据首地址
			dwBytesWrite, //要发送的数据字节数
			&dwBytesWrite, //DWORD*，用来接收返回成功发送的数据字节数
			NULL); //NULL为同步发送，OVERLAPPED*为异步发送
		if (!bWriteStat)
		{
			return false;
		}
		return dwBytesWrite;
	}
	else
	{
		DWORD dwBytesWrite = len; //成功写入的数据字节数
		DWORD dwErrorFlags; //错误标志
		COMSTAT comStat; //通讯状态
		OVERLAPPED m_osWrite; //异步输入输出结构体

		//创建一个用于OVERLAPPED的事件处理，不会真正用到，但系统要求这么做
		memset(&m_osWrite, 0, sizeof(m_osWrite));
		m_osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, L"WriteEvent");

		ClearCommError(hCom, &dwErrorFlags, &comStat); //清除通讯错误，获得设备当前状态
		BOOL bWriteStat = WriteFile(hCom, //串口句柄
			buf, //数据首地址
			dwBytesWrite, //要发送的数据字节数
			&dwBytesWrite, //DWORD*，用来接收返回成功发送的数据字节数
			&m_osWrite); //NULL为同步发送，OVERLAPPED*为异步发送
		if (!bWriteStat)
		{
			if (GetLastError() == ERROR_IO_PENDING) //如果串口正在写入
			{
				WaitForSingleObject(m_osWrite.hEvent, 1000); //等待写入事件1秒钟
			}
			else
			{
				ClearCommError(hCom, &dwErrorFlags, &comStat); //清除通讯错误
				CloseHandle(m_osWrite.hEvent); //关闭并释放hEvent内存
				return 0;
			}
		}
		return dwBytesWrite;
	}
}

int SerialPort::ReadFromPort(void * buf,int len)
{
	if (this->spSettingInfo.dwFlagsAndAttributes)
	{
		//同步方式
		DWORD wCount = len; //成功读取的数据字节数
		BOOL bReadStat = ReadFile(hCom, //串口句柄
			buf, //数据首地址
			wCount, //要读取的数据最大字节数
			&wCount, //DWORD*,用来接收返回成功读取的数据字节数
			NULL); //NULL为同步发送，OVERLAPPED*为异步发送
		if (!bReadStat)
		{
			return 0;
		}
		return wCount;
	}
	else
	{
		DWORD wCount = len; //成功读取的数据字节数
		DWORD dwErrorFlags; //错误标志
		COMSTAT comStat; //通讯状态
		OVERLAPPED m_osRead; //异步输入输出结构体

		//创建一个用于OVERLAPPED的事件处理，不会真正用到，但系统要求这么做
		memset(&m_osRead, 0, sizeof(m_osRead));
		m_osRead.hEvent = CreateEvent(NULL, TRUE, FALSE, L"ReadEvent");

		ClearCommError(hCom, &dwErrorFlags, &comStat); //清除通讯错误，获得设备当前状态
		if (!comStat.cbInQue)return 0; //如果输入缓冲区字节数为0，则返回false

		BOOL bReadStat = ReadFile(hCom, //串口句柄
			buf, //数据首地址
			wCount, //要读取的数据最大字节数
			&wCount, //DWORD*,用来接收返回成功读取的数据字节数
			&m_osRead); //NULL为同步发送，OVERLAPPED*为异步发送
		if (!bReadStat)
		{
			if (GetLastError() == ERROR_IO_PENDING) //如果串口正在读取中
			{
				//GetOverlappedResult函数的最后一个参数设为TRUE
				//函数会一直等待，直到读操作完成或由于错误而返回
				GetOverlappedResult(hCom, &m_osRead, &wCount, TRUE);
			}
			else
			{
				ClearCommError(hCom, &dwErrorFlags, &comStat); //清除通讯错误
				CloseHandle(m_osRead.hEvent); //关闭并释放hEvent的内存
				return 0;
			}
		}
		return wCount;
	}
}

SerialPort::SerialPort()
{
	this->spSettingInfo.serialName = "COM1";
	this->spSettingInfo.dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;//读或写
	this->spSettingInfo.dwShareMode = 0;
	this->spSettingInfo.lpSecurityAttributes = NULL;
	this->spSettingInfo.dwCreationDistribution = OPEN_EXISTING;
	this->spSettingInfo.dwFlagsAndAttributes = FILE_FLAG_OVERLAPPED;//异步
	this->spSettingInfo.hTemplateFile = NULL;
	this->hCom = NULL;
}


SerialPort::~SerialPort()
{
	this->unInitSerialPort();
}
