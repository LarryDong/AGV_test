
#pragma once
#ifndef __VIEWER_H
#define __VIEWER_H

#include "label.h"
#include "tag.h"
#include <opencv2/opencv.hpp>

void drawTagRoi(const Mat& src, Label label, string name = "tagRoi", cv::Scalar color = cv::Scalar(0, 0, 255));
void drawDecodeResults(const Mat& src, Label label, string name = "results");
void showLShapePosition(const Mat& src, Label label);
void showDecodeInformation(const Label& label);
void showMiddlePointByTags(const Mat& src, vector<Point2f> mp);

void showTagRoi(Label label, string name = "tagRoi");

#endif

