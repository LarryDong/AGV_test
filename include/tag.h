
#pragma once

#ifndef __TAG_H
#define __TAG_H

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// tag is only one dm code.
class Tag {
public:
	Tag(const Mat& src, const Point& position) {
		src.copyTo(mat);
		if (mat.type() != CV_8UC1) {
			cout << "Label type should be 8uc1" << endl;
			cvtColor(mat, mat, COLOR_BGR2GRAY);
		}
		matOriginInLabel = position;
		width = mat.cols;
		height = mat.rows;
		isSubpixelObtained = false;
		//rect = Rect(pos.x, pos.y, mat.cols, mat.rows);
	}

	int update(void) {
		width = mat.cols;
		height = mat.rows;
		//rect = Rect(pos.x, pos.y, mat.cols, mat.rows);
		return 0;
	}

	/*
	L0
	L1-L2
	*/
	Mat mat;
	int width = 0, height = 0;
	Point matOriginInLabel;
	Point _L0;
	Point _L1;
	Point _L2;
	double angle;
	//double weight;
	double polarity;

	bool isSubpixelObtained;
	Point2f _L0_float;
	Point2f _L1_float;
	Point2f _L2_float;

	// data:"6500000011", blockIndex:65, labelIndex:11, checkString:"000000"
	string data;
	int blockIndex = -1; 
	int labelIndex = -1;
	string checkString;

	// flags
	bool isDecodeSuccess = false;
	bool isValid = false;
	
	// functions.
	int findLShape(void);
	void decode(void);
	bool checkValidation(void);		// check whether the tag is valid.
	int calcProperties(void);		// calculate properties: angle and weight, ...
	
	int contour2Freeman(const vector<Point>& con, vector<int>& freeman);
	vector<Point> findVertices(const Mat& src, const vector<Point>& contour, bool isInclined);
	bool checkCodeInclination(const vector<int>& freeman);
	
	int findSubPixelLShape(void);
	int calcPolarity(void);

private:
	int bin_threshold = 128;
	long timeout_ms = 30;		// decode time are limited to xxx ms.
};

#endif