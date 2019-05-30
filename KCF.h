#pragma once
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
class KCF
{
private:
	cv::MultiTracker trackers;
public:
	KCF();
	KCF(cv::Mat FirstFrame);//initilizeFilter
	bool KCF_tracking(cv::Mat frame);
	~KCF();
};

