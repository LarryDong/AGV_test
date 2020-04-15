
#pragma once

#ifndef __LABEL_H
#define __LABEL_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include "tag.h"

using namespace std;
using namespace cv;

enum LabelState{Default, No_Contour, No_Tag, Tag_Conflict, Tag_Missing, Tag_Perfect};

// label is the whole paper.
class Label {
public:
	Label(const Mat& src) {
		src.copyTo(mat);
		if (mat.type() != CV_8UC1) {
			cout << "Label type should be 8uc1" << endl;
			cvtColor(mat, mat, COLOR_BGR2GRAY);
		}
		angle = 0;
	}

	int getTagROIsByContour(const Mat& src);	// get all might-be ROIs.
	int getAllLshapePosition(void);		// get all L-shape
	int updateTagROIs(void);			// update tag ROIs by L-shape.
	int decodeAll(void);				// decode in all L-shape region.
	int removeInvalidTags(void);		// remove tag roi not decoded.
	int calcAllTagsInfo(void);			// calculate all tags information.
	int calcAngleOffset(void);
	int calcPositionOffset(void);
	int findAllTagLSubpixel(void);

	// data.
	Mat mat;
	vector<Tag> tagsVector;
	vector<Point2f> allMiddlePoints;
	Point2f middlePoint;
	double angle;
	LabelState state = Default;

	// to be continue
	int index = -1;
	string information = "";
	//int obtainInformation(void);	// obtain label information.


private:
	const int bin_threshold = 128;
	//const int valid_tag_length = 80;
	// const int valid_tag_length = 60;
	const int valid_tag_contour_min = 200;		// use absolute value now.
	const int valid_tag_contour_max = 500;		// use absolute value now.
	const int valid_tag_contour_ratio = 50;
	const int tag_roi_margin = 10;
};

#endif
