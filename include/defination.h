
#pragma once
#ifndef __DEFINATION_H
#define __DEFINATION_H

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/*
0 1      56 66
3 2      55 65
*/


#define SYSTEM_LINUX

// #define DM_BlockIndex_0 56
// #define DM_BlockIndex_1 66
// #define DM_BlockIndex_2 65
// #define DM_BlockIndex_3 55
// #define DM_CheckString "000000"

// // 6500000011
// #define DM_Data_Length 10
// #define DM_Data_BlockIndex_Begin	0
// #define DM_Data_BlockIndex_End		1
// #define DM_Data_LabelIndex_Begin		8
// #define DM_Data_LabelIndex_End		9
// #define DM_Data_Check_Begin			2
// #define DM_Data_Check_End			7

// // Label layout information.

// #define Label_Tag_Size	13
// #define Label_Tag_Gap	2.5



// for paper.
/*
0 1      1 2
3 2      3 4
*/
#define DM_BlockIndex_0 01
#define DM_BlockIndex_1 02
#define DM_BlockIndex_2 03
#define DM_BlockIndex_3 04
#define DM_CheckString "0000"

// 0001 0000 01
#define DM_Data_Length 10
#define DM_Data_BlockIndex_Begin	8
#define DM_Data_BlockIndex_End		9
#define DM_Data_LabelIndex_Begin		0
#define DM_Data_LabelIndex_End		3
#define DM_Data_Check_Begin			4
#define DM_Data_Check_End			7

// Label layout information.

#define Label_Tag_Size	20
#define Label_Tag_Gap	10


// show image
// #define _SHOW_IMAGE
//#define _SHOW_INFO

#endif

