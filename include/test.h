
#pragma once
#ifndef __TEST_H
#define __TEST_H


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int readAndSaveImages(const string& filePath, const bool ctrl = true, const string & fileType = ".bmp");

void tool_imporveResolution();

void tool_saveContour();

void tool_vertex();


void tool_videoSave();


void tool_findGt();
void gt_trackber(int, void*);
void tool_gtTest();


void tool_histogram();

void tool_bipolarity();
void tool_gtCircle();

#define GT_SCALE 4

#endif 
