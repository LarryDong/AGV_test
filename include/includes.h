
#pragma once
#ifndef __INCLUDES_H
#define __INCLUDES_H

// system files.
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

// personal files.
#include "label.h"
#include "tag.h"
#include "test.h"
#include "defination.h"
#include "viewer.h"
#include "debug.h"
#include "tool.h"

using namespace std;
using namespace cv;

void process(const Mat& src);

#endif

