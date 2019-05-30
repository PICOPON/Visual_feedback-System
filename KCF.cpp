#include "KCF.h"
KCF::KCF()
{
}

KCF::KCF(cv::Mat FirstFrame)
{
	std::vector<cv::Rect> rois;
	selectROIs("rois", FirstFrame,rois, false);
	std::vector<cv::Rect2d> objects;
	std::vector<cv::Ptr<cv::Tracker>> algorithms;
	for (auto i = 0; i < objects.size(); i++)
	{
		objects.push_back(rois[i]);
		algorithms.push_back(cv::TrackerKCF::create());
	}
	this->trackers.add(algorithms, FirstFrame, objects);
}

bool KCF::KCF_tracking(cv::Mat frame)
{
	if (frame.rows == 0 || frame.cols == 0)
		return false;
	else
	{
		if (this->trackers.update(frame))
		{
			for (auto j = 0; j < this->trackers.getObjects().size(); j++)
			{
				cv::rectangle(frame, trackers.getObjects()[j], cv::Scalar(255, 0, 0),2,1);
			}
			cv::namedWindow("tracker", 0);
			cv::imshow("tracker", frame);
		}
	}
}
KCF::~KCF()
{
	std::cout << "KCF released";
}
