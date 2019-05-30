#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Visual_feedback_system.h"
#include <qtimer.h>
#include "SerialPort.h"
#include "KCF.h"

class Visual_feedback_system : public QMainWindow
{
	Q_OBJECT

public:
	Visual_feedback_system(QWidget *parent = Q_NULLPTR);
	//���湹�캯��
	bool initSystem(); //�Զ��庯��
private:
	Ui::Visual_feedback_systemClass ui;//ui�����
	QTimer* ptimer;
	QTimer* viewTimer;
	int m_nDeviceNum = 0;
	int m_nDeviceCurSel = -1;//�豸���
	int timer_count = 0;//��ʱ��
	int nCaptureWidth;
	int nCaptureHeight;
	int nCaptureBitCount;
	int pixelCount;
	KCF* kcf_traking;//KCF for Tracking
signals:
	 void timeout();
	//�Զ����ź�
private slots:  //�Զ����
	void on_AddButton_Clicked();
	void on_TrackButton_Clicked();
	void on_SetButton_Clicked();
	void on_StartBtn_Clicked();
	void on_StopBtn_Clicked();
	void on_TimeRestBtn_Clicked();
	void on_initTrackerBtn_Clicked();
	void on_preViewBtn_Clicked();
	void on_StopPreViewBtn_Clicked();
	void preViewStart();
};