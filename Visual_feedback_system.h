#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Visual_feedback_system.h"
#include <qtimer.h>


class Visual_feedback_system : public QMainWindow
{
	Q_OBJECT

public:
	Visual_feedback_system(QWidget *parent = Q_NULLPTR);
	//界面构造函数
	bool initSystem(); //自定义函数
private:
	Ui::Visual_feedback_systemClass ui;//ui设计器
	int m_nDeviceNum = 0;
	int m_nDeviceCurSel = -1;
	int timer_count = 0;
	QTimer* ptimer;
signals:
	 void timeout();
	//自定义信号
private slots:  //自定义槽
	void on_AddButton_Clicked();
	void on_TrackButton_Clicked();
	void on_SetButton_Clicked();
	void on_StartBtn_Clicked();
	void on_StopBtn_Clicked();
	void on_TimeRestBtn_Clicked();

};