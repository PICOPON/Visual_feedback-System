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
	this->ui.StopBtn->setEnabled(false);
	this->ptimer = new QTimer(this);
	QObject::connect(this->ptimer, SIGNAL(timeout()), this, SLOT(on_TrackButton_Clicked()));
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
	KSJ_Init();
	KSJ_UnInit();
	KSJ_Init();
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
	//std::ofstream fout;
	//fout.open("E://1.txt");
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
	cv::Mat souceImg(nCaptureHeight, nCaptureWidth, CV_8UC3,pRgbData);
	cv::namedWindow("img", 0);
	cv::imshow("img", souceImg);
	//------------------------------------------------
	//cv::imwrite("E://1.jpg",souceImg);
	//QPixmap myPix=QPixmap::fromImage(QImage((unsigned char*)souceImg.data, souceImg.cols, souceImg.rows, QImage::Format_RGB888).rgbSwapped());
	//this->ui.ImgViewLabel->setPixmap(myPix);
	//this->ui.ImgViewLabel->setScaledContents(true);
	//this->ui.ImgViewLabel->show();
	//-------------------------------------------------------
	this->ui.timeCounts->setText(QString::number(timer_count));
	timer_count++;
	delete[] pRgbData;
	//fout << timer_count;
}

void Visual_feedback_system::on_SetButton_Clicked()
{
	int nColStart = 0;
	int nRowStart = 0;
	int nColSize = 0;
	int nRowSize = 0;
	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;
	nColStart = (int32_t)ui.TextBox_CAPTURE_COL_START;
	nRowStart = (int32_t)ui.TextBox_CAPTURE_ROW_START;
	nColSize = (int32_t)ui.TextBox_CAPTURE_COL_SIZE;
	nRowSize = (int32_t)ui.TextBox_CAPTURE_ROW_SIZE;
	KSJ_CaptureGetDefaultFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	ui.TextBox_CAPTURE_COL_START->setText(QString::number(nColStart));
	ui.TextBox_CAPTURE_ROW_START->setText(QString::number(nRowStart));
	ui.TextBox_CAPTURE_COL_SIZE->setText(QString::number(nColSize));
	ui.TextBox_CAPTURE_ROW_SIZE->setText(QString::number(nRowSize));
}

void Visual_feedback_system::on_StartBtn_Clicked()
{
	this->ui.StopBtn->setEnabled(true);
	this->ptimer->start(30);
}

void Visual_feedback_system::on_StopBtn_Clicked()
{
	this->ptimer->stop();
}

void Visual_feedback_system::on_TimeRestBtn_Clicked()
{
	this->ui.timeCounts->setText(QString::number(0));
	this->timer_count = 0;
}


