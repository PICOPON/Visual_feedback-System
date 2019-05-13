#include "Visual_feedback_system.h"
#include <tchar.h>
#include <stdint.h>
#include <string>
#include <opencv2/opencv.hpp>//opencv api
extern "C"
{
#include "KSJApiBase.h"
#include "KSJApiBayer.h"
}//camera api
typedef unsigned char BYTE;

Visual_feedback_system::Visual_feedback_system(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

bool Visual_feedback_system::initSystem()
{
	try
	{
		KSJ_Init();
		KSJ_UnInit();
		KSJ_Init();
	}
	catch(const char * s)
	{
		std::cout << s;
		return false;
	}
	return true;
}

void Visual_feedback_system::on_AddButton_Clicked()
{
	QString num_device;
	m_nDeviceNum = KSJ_DeviceGetCount();
	ui.DeviceNum_Label->setNum(m_nDeviceNum);
	if (m_nDeviceNum == 0)
	{
		m_nDeviceCurSel = -1;
	}
	if (m_nDeviceCurSel >= m_nDeviceNum)
	{
		m_nDeviceCurSel = 0;
	}
	for (int i = 0; i < m_nDeviceNum; i++)
	{
		ui.ComboBox_DEVICE_LIST->insertItem(0,num_device.setNum(i));
	}
	m_nDeviceCurSel = ui.ComboBox_DEVICE_LIST->currentIndex();
	
}

void Visual_feedback_system::on_TrackButton_Clicked()
{
	if (m_nDeviceCurSel == -1) return;
	KSJ_BAYERMODE* pBayerMode=new KSJ_BAYERMODE[1];
	KSJ_BayerGetDefaultMode(m_nDeviceCurSel,pBayerMode);
	int nCaptureWidth;
	int nCaptureHeight;
	int nCaptureBitCount;
	int nRet = KSJ_CaptureGetSizeEx(m_nDeviceCurSel, &nCaptureWidth, &nCaptureHeight, &nCaptureBitCount);
	int pixelCount = nCaptureWidth * nCaptureHeight * 3;
	BYTE* pRgbData = new BYTE[pixelCount];
	KSJ_CaptureRgbData(m_nDeviceCurSel, pRgbData);


}

void Visual_feedback_system::on_SetButton_Clicked()
{
	int nColStart = 0;
	int nRowStart = 0;
	int nColSize = 0;
	int nRowSize = 0;
	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;
	nColStart = (int)ui.TextBox_CAPTURE_COL_START;
	nRowStart = (int)ui.TextBox_CAPTURE_ROW_START;
	nColSize = (int)ui.TextBox_CAPTURE_COL_SIZE;
	nRowSize = (int)ui.TextBox_CAPTURE_ROW_SIZE;
	KSJ_CaptureSetFieldOfView(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode);


}


