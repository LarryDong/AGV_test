#pragma once
#ifndef __TOOL_H
#define __TOOL_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// convert the point int image coordinate to normal coordinate.
template  <typename T> T image2normal(T pImg, const int rows){
	//assert(pImg.y < rows);
	T pNorm;
	pNorm.x = pImg.x;
	pNorm.y = rows - pImg.y;
	return pNorm;
}

// find the max value of 4 paramters.
#define _Tool_MAX4(a,b,c,d) max(a,max(b,max(c,d)))
#define _Tool_MIN4(a,b,c,d) min(a,min(b,min(c,d)))

// do not exceed the boundary.
#define _Tool_UpBound(v, bound) min(v, bound)
#define _Tool_DownBound(v, bound) max(v, bound)


// check whether to do this function
#define _CheckEqual_Return(lhs, rhs, rvalue) \
	if (lhs == rhs) {	\
		return rvalue;	\
	}

#endif
