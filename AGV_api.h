
// API
#pragma once

// system files.
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <sys/time.h>

// user head files.
#include "label.h"
#include "tag.h"
#include "defination.h"
#include "calib.h"
#include "tool.h"
#include "viewer.h"

using namespace std;
using namespace cv;


// parameters.
class AGV_System_Config{

public:
	AGV_System_Config();
	bool checkConfig();

	Size resolution_;
	string calib_image_;
	Rect roi_;
	bool show_image_flag_;
	int bin_thresh_;
};



class AGV_System{

public:
	AGV_System() { cout << "[Error]. System should be init with Config!" << endl; }
	AGV_System(AGV_System_Config config);

	bool decode(const Mat& src);		// main function

	void showResults(){
		cout << "No.[" << id_ << "], "
			 << "center: (" << center_.x << ", " << center_.y << "), "
			 << "angle: " << angle_ << ", "
			 << "states:[" << states_[0] << states_[1] << states_[2] << states_[3] << "], "
			 << "time: " << time_ms_ << " ms" << endl;
	}
	
	Point2f center_;	// center position
	double angle_;		// rotation angle
	Vec4i states_;		// which block is decoded
	int id_;				// label id
	double time_ms_;		// decode time in ms.

private:
	Size resolution_;	// default: 640x400
	Rect roiRect_;
	bool show_image_flag_;		// default: false
	PhotoCalib pc_;		// photo calib.
};




