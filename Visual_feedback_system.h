#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Visual_feedback_system.h"

class Visual_feedback_system : public QMainWindow
{
	Q_OBJECT

public:
	Visual_feedback_system(QWidget *parent = Q_NULLPTR);

private:
	Ui::Visual_feedback_systemClass ui;
private slots:
	void on_AddButton_Clicked();

};
