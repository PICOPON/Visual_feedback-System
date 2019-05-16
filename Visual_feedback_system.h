#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Visual_feedback_system.h"
#include <qtimer.h>


class Visual_feedback_system : public QMainWindow
{
	Q_OBJECT

public:
	Visual_feedback_system(QWidget *parent = Q_NULLPTR);
	//���湹�캯��
	bool initSystem(); //�Զ��庯��
private:
	Ui::Visual_feedback_systemClass ui;//ui�����
	int m_nDeviceNum = 0;
	int m_nDeviceCurSel = -1;
	int timer_count = 0;
	QTimer* ptimer;
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

};