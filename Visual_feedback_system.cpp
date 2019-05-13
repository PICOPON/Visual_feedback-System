#include "Visual_feedback_system.h"
#include "opencv2/opencv.hpp"

Visual_feedback_system::Visual_feedback_system(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void Visual_feedback_system::on_AddButton_Clicked()
{
	cv::Mat img = cv::imread("E://pic/1.jpg");
	cv::namedWindow("img", CV_WINDOW_NORMAL);                                
	cv::imshow("img", img);                                        
	cv::waitKey(0);
}
