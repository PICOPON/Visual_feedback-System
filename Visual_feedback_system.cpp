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
	this->ui.StopPreView->setEnabled(false);

	this->ptimer = new QTimer(this);

	QObject::connect(this->ptimer, SIGNAL(timeout()), this, SLOT(on_TrackButton_Clicked()));

	this->initSystem();
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
//添加camera设备
void Visual_feedback_system::on_TrackButton_Clicked()
{
	//SerialPort sPort;
	//if (sPort.InitSerialPort("COM2", 9600, 0, 8, 1, ReadAndWrite, Synchronous))//串口模式和参数设置
	//{
		//sPort.WriteToPort("helloworld", 10);//写入串口数据
	//}
	//std::ofstream fout;
	//fout.open("E://1.txt");
	BYTE* pRgbData = new BYTE[this->pixelCount];
	KSJ_CaptureRgbData(m_nDeviceCurSel, pRgbData);
	cv::Mat frame(this->nCaptureHeight, this->nCaptureWidth, CV_8UC3, pRgbData);
	cv::resize(frame, frame, cv::Size(1000, 800));
	Rect2d roi;
	// create a tracker object
	Ptr<Tracker> tracker = TrackerKCF::create();
	// set input video
	roi = selectROI("tracker", frame);
	//quit if ROI was not selected
	// initialize the tracker
	tracker->init(frame, roi);
	// perform the tracking process
	printf("Start the tracking process, press ESC to quit.\n");
	for (;; ) {
		KSJ_CaptureRgbData(m_nDeviceCurSel, pRgbData);
		cv::Mat frame(this->nCaptureHeight, this->nCaptureWidth, CV_8UC3, pRgbData);
		cv::resize(frame, frame, cv::Size(1000, 800));
		// stop the program if no more images
		if (frame.rows == 0 || frame.cols == 0)
			break;
		// update the tracking result
		tracker->update(frame, roi);
		// draw the tracked object
		rectangle(frame, roi, Scalar(255, 0, 0), 2, 1);
		// show image with the tracked object
		imshow("tracker", frame);
		//quit on ESC button
		if (waitKey(1) == 27)break;
	}
	//this->ui.timeCounts->setText(QString::number(timer_count));
	//timer_count++;
	//delete[] pRgbData;
	/*
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
		*/
};
	

void Visual_feedback_system::on_SetButton_Clicked()
{
	int nColStart = 0;
	int nRowStart = 0;
	int nColSize = 3800;
	int nRowSize = 3800;
	int EXPOSURE = 6000;
	KSJ_ADDRESSMODE ColAddressMode = KSJ_SKIPNONE;
	KSJ_ADDRESSMODE RowAddressMode = KSJ_SKIPNONE;
	//nColStart = (int32_t)ui.TextBox_CAPTURE_COL_START;
	//nRowStart = (int32_t)ui.TextBox_CAPTURE_ROW_START;
	//nColSize = (int32_t)ui.TextBox_CAPTURE_COL_SIZE;
	//nRowSize = (int32_t)ui.TextBox_CAPTURE_ROW_SIZE;
	//EXPOSURE = QString::number(ui.KSJ_EXPOSURE_LINES_Text.);
	KSJ_CaptureSetFieldOfView(m_nDeviceCurSel, nColStart, nRowStart, nColSize, nRowSize, ColAddressMode, RowAddressMode);
	KSJ_SetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, EXPOSURE);
	//设置采集视场和
	KSJ_CaptureGetDefaultFieldOfView(m_nDeviceCurSel, &nColStart, &nRowStart, &nColSize, &nRowSize, &ColAddressMode, &RowAddressMode);
	KSJ_GetParam(m_nDeviceCurSel, KSJ_EXPOSURE_LINES, &EXPOSURE);
	ui.TextBox_CAPTURE_COL_START->setText(QString::number(nColStart));
	ui.TextBox_CAPTURE_ROW_START->setText(QString::number(nRowStart));
	ui.TextBox_CAPTURE_COL_SIZE->setText(QString::number(nColSize));
	ui.TextBox_CAPTURE_ROW_SIZE->setText(QString::number(nRowSize));
	ui.KSJ_EXPOSURE_LINES_Text->setText(QString::number(EXPOSURE));
	//KSJ_ExposureTimeSet(m_nDeviceCurSel,(int)ui.ExposureTime_Text);
}
//初始设置
void Visual_feedback_system::on_StartBtn_Clicked()
{
	this->ui.StopBtn->setEnabled(true);
	this->ptimer->start(30);
}
//计时开始
void Visual_feedback_system::on_StopBtn_Clicked()
{
	this->ptimer->stop();
}
//计时停止
void Visual_feedback_system::on_TimeRestBtn_Clicked()
{
	this->ui.timeCounts->setText(QString::number(0));
	this->timer_count = 0;
}
//时间复位
void Visual_feedback_system::on_initTrackerBtn_Clicked()
{
	if (m_nDeviceCurSel == -1) return;
	KSJ_BAYERMODE* pBayerMode = new KSJ_BAYERMODE[1];
	KSJ_BayerGetDefaultMode(m_nDeviceCurSel, pBayerMode);//获取默认Bayer模式
	int nRet = KSJ_CaptureGetSizeEx(m_nDeviceCurSel, &this->nCaptureWidth, &this->nCaptureHeight, &this->nCaptureBitCount);
	this->pixelCount = (this->nCaptureWidth) * (this->nCaptureHeight) * 3;
}
void Visual_feedback_system::on_preViewBtn_Clicked()
{
	if (m_nDeviceCurSel == -1) return;
	KSJ_BAYERMODE* pBayerMode = new KSJ_BAYERMODE[1];
	KSJ_BayerGetDefaultMode(m_nDeviceCurSel, pBayerMode);//获取默认Bayer模式
	int nRet = KSJ_CaptureGetSizeEx(m_nDeviceCurSel, &this->nCaptureWidth, &this->nCaptureHeight, &this->nCaptureBitCount);
	this->pixelCount = (this->nCaptureWidth) * (this->nCaptureHeight) * 3;
	BYTE* pRgbData = new BYTE[this->pixelCount];
	KSJ_CaptureRgbData(m_nDeviceCurSel, pRgbData);
	cv::Mat SourceImg(this->nCaptureHeight, this->nCaptureWidth, CV_8UC3, pRgbData);
	cv::resize(SourceImg, SourceImg, cv::Size(1000, 800));
	cv::namedWindow("preView", 0);
	cv::imshow("preView", SourceImg);
	delete[] pRgbData;
}

void Visual_feedback_system::on_StopPreViewBtn_Clicked()
{
	this->viewTimer->stop();
}

void Visual_feedback_system::preViewStart()
{

	
}

//Tracker初始化

