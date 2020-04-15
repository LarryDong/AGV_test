
#pragma once

#ifndef __CALIB_H
#define __CALIB_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

class PhotoCalib{

public:
	PhotoCalib(){};

	void calibImage(Mat& image);		// calib an image.

	void set_bgImg(const Mat src) { bgImg = src.clone(); }
	void set_calibMat();

private:
	Mat bgImg;		// background picture.
	Mat calibMat;		// CV_32FC1, to scale.
};

#endif
