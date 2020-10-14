
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

	Size resolution_;			// default: 640x400
	string calib_image_;
	Rect roi_;
	bool show_image_flag_;		// Show image. default: false
	bool show_more_info_flag_;	// Show more info. defalut: false.
	
	int valid_contour_max_;
	int valid_contour_min_;

    // params for (adaptive) threshold
    int bin_thresh_;                // set the fixed threshold. default: 90;
    bool is_adaptive_threshold_;    // check if adaptive. default: false
    int adaptive_threshold_low_, adaptive_threshold_high_;      // adaptive threshold between these two values. default: [1,999]
    int adaptive_size_, adaptive_offset_;   // block size and constant value for offset.
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
	int valid_contour_max_, valid_contour_min_;

	
private:
	Size resolution_;	
	Rect roiRect_;
	bool show_image_flag_;
	bool show_more_info_flag_;
	PhotoCalib pc_;		// photo calib.
    
    // Use global variables to pass the value now...
    // bool is_adaptive_;        // check if adaptive.
    // int thLow_, thHigh_;      // adaptive threshold between these two values.
};




