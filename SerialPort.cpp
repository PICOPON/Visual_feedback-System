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
		if(!SetupComm(hCom,1024,1024))//�趨������Ϊ1KB
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
			dcb.Parity = NOPARITY; //��У��
			break;
		case 1:
			dcb.Parity = ODDPARITY; //��У��
			break;
		case 2:
			dcb.Parity = EVENPARITY; //żУ��
			break;
		case 3:
			dcb.Parity = MARKPARITY; //���У��
			break;
		}
		switch (stopbit)
		{
		case 1:
			dcb.StopBits = ONESTOPBIT; //1λֹͣλ
			break;
		case 2:
			dcb.StopBits = TWOSTOPBITS; //2λֹͣλ
			break;
		case 3:
			dcb.StopBits = ONE5STOPBITS; //1.5λֹͣλ
			break;
		}
		if (!SetCommState(hCom, &dcb))
		{
			return false;
		}
		//��ʱ����
		COMMTIMEOUTS TimeOuts;
		TimeOuts.ReadIntervalTimeout = 1000; //�������ʱ
		TimeOuts.ReadTotalTimeoutMultiplier = 500; //��ʱ��ϵ��
		TimeOuts.ReadTotalTimeoutConstant = 5000; //��ʱ�䳣��
		TimeOuts.WriteTotalTimeoutMultiplier = 500; // дʱ��ϵ��
		TimeOuts.WriteTotalTimeoutConstant = 2000; //дʱ�䳣��
		SetCommTimeouts(hCom, &TimeOuts);

		PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);//��մ��ڻ�����
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
		DWORD dwBytesWrite = len; //�ɹ�д��������ֽ���
		BOOL bWriteStat = WriteFile(hCom, //���ھ��
			buf, //�����׵�ַ
			dwBytesWrite, //Ҫ���͵������ֽ���
			&dwBytesWrite, //DWORD*���������շ��سɹ����͵������ֽ���
			NULL); //NULLΪͬ�����ͣ�OVERLAPPED*Ϊ�첽����
		if (!bWriteStat)
		{
			return false;
		}
		return dwBytesWrite;
	}
	else
	{
		DWORD dwBytesWrite = len; //�ɹ�д��������ֽ���
		DWORD dwErrorFlags; //�����־
		COMSTAT comStat; //ͨѶ״̬
		OVERLAPPED m_osWrite; //�첽��������ṹ��

		//����һ������OVERLAPPED���¼��������������õ�����ϵͳҪ����ô��
		memset(&m_osWrite, 0, sizeof(m_osWrite));
		m_osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, L"WriteEvent");

		ClearCommError(hCom, &dwErrorFlags, &comStat); //���ͨѶ���󣬻���豸��ǰ״̬
		BOOL bWriteStat = WriteFile(hCom, //���ھ��
			buf, //�����׵�ַ
			dwBytesWrite, //Ҫ���͵������ֽ���
			&dwBytesWrite, //DWORD*���������շ��سɹ����͵������ֽ���
			&m_osWrite); //NULLΪͬ�����ͣ�OVERLAPPED*Ϊ�첽����
		if (!bWriteStat)
		{
			if (GetLastError() == ERROR_IO_PENDING) //�����������д��
			{
				WaitForSingleObject(m_osWrite.hEvent, 1000); //�ȴ�д���¼�1����
			}
			else
			{
				ClearCommError(hCom, &dwErrorFlags, &comStat); //���ͨѶ����
				CloseHandle(m_osWrite.hEvent); //�رղ��ͷ�hEvent�ڴ�
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
		//ͬ����ʽ
		DWORD wCount = len; //�ɹ���ȡ�������ֽ���
		BOOL bReadStat = ReadFile(hCom, //���ھ��
			buf, //�����׵�ַ
			wCount, //Ҫ��ȡ����������ֽ���
			&wCount, //DWORD*,�������շ��سɹ���ȡ�������ֽ���
			NULL); //NULLΪͬ�����ͣ�OVERLAPPED*Ϊ�첽����
		if (!bReadStat)
		{
			return 0;
		}
		return wCount;
	}
	else
	{
		DWORD wCount = len; //�ɹ���ȡ�������ֽ���
		DWORD dwErrorFlags; //�����־
		COMSTAT comStat; //ͨѶ״̬
		OVERLAPPED m_osRead; //�첽��������ṹ��

		//����һ������OVERLAPPED���¼��������������õ�����ϵͳҪ����ô��
		memset(&m_osRead, 0, sizeof(m_osRead));
		m_osRead.hEvent = CreateEvent(NULL, TRUE, FALSE, L"ReadEvent");

		ClearCommError(hCom, &dwErrorFlags, &comStat); //���ͨѶ���󣬻���豸��ǰ״̬
		if (!comStat.cbInQue)return 0; //������뻺�����ֽ���Ϊ0���򷵻�false

		BOOL bReadStat = ReadFile(hCom, //���ھ��
			buf, //�����׵�ַ
			wCount, //Ҫ��ȡ����������ֽ���
			&wCount, //DWORD*,�������շ��سɹ���ȡ�������ֽ���
			&m_osRead); //NULLΪͬ�����ͣ�OVERLAPPED*Ϊ�첽����
		if (!bReadStat)
		{
			if (GetLastError() == ERROR_IO_PENDING) //����������ڶ�ȡ��
			{
				//GetOverlappedResult���������һ��������ΪTRUE
				//������һֱ�ȴ���ֱ����������ɻ����ڴ��������
				GetOverlappedResult(hCom, &m_osRead, &wCount, TRUE);
			}
			else
			{
				ClearCommError(hCom, &dwErrorFlags, &comStat); //���ͨѶ����
				CloseHandle(m_osRead.hEvent); //�رղ��ͷ�hEvent���ڴ�
				return 0;
			}
		}
		return wCount;
	}
}

SerialPort::SerialPort()
{
	this->spSettingInfo.serialName = "COM1";
	this->spSettingInfo.dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;//����д
	this->spSettingInfo.dwShareMode = 0;
	this->spSettingInfo.lpSecurityAttributes = NULL;
	this->spSettingInfo.dwCreationDistribution = OPEN_EXISTING;
	this->spSettingInfo.dwFlagsAndAttributes = FILE_FLAG_OVERLAPPED;//�첽
	this->spSettingInfo.hTemplateFile = NULL;
	this->hCom = NULL;
}


SerialPort::~SerialPort()
{
	this->unInitSerialPort();
}
