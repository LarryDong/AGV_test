
#pragma once

#ifndef __DEBUG_H
#define __DEBUG_H

#include "includes.h"
#include <sys/time.h>


void createControlBar(void);
void onTrackbar(int, void*);
void onMouseCallback(int event, int x, int y, int flags, void* param);

class My_Timer{

public:
	My_Timer(){
	extractContour = -1;
	findLShape = -1;
	decode = -1;
	decodeOne = -1;
	combine = -1;
	}

	void begin(){
		gettimeofday(&tBegin, NULL);
	}
	void begin2(){
		gettimeofday(&tBegin2, NULL);
	}
	void begin3(){
		gettimeofday(&tBegin3, NULL);
	}

	double end(){
		timeval tEnd;
		gettimeofday(&tEnd, NULL);
		return 1000 * (tEnd.tv_sec - tBegin.tv_sec) + (tEnd.tv_usec - tBegin.tv_usec) / 1000.0f;
	}
	double end2(){
		timeval tEnd;
		gettimeofday(&tEnd, NULL);
		return 1000 * (tEnd.tv_sec - tBegin2.tv_sec) + (tEnd.tv_usec - tBegin2.tv_usec) / 1000.0f;
	}

	double end3(){
		timeval tEnd;
		gettimeofday(&tEnd, NULL);
		return 1000 * (tEnd.tv_sec - tBegin3.tv_sec) + (tEnd.tv_usec - tBegin3.tv_usec) / 1000.0f;
	}

	void showTimer(){
		cout << "Time used. Contours: " << extractContour 
		<< ", find L: " << findLShape 
		<< ", decode one: " << decodeOne
		<< ", decode all: " << decode 
		<< ", combine: " << combine 
		<< endl;
	}
	
	double extractContour;
	double findLShape;

	double decode;
	double decodeOne;

	double combine;

private:
	timeval tBegin, tBegin2, tBegin3;
};


#endif

