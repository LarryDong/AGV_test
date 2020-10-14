
#include "AGV_api.h"
#include <string>
#include <iostream>
#include <opencv2/video.hpp>

using namespace std;


const string filePath = "/home/larrydong/Desktop/case/";

Mat g_src;

void process(const Mat& src){

	AGV_System_Config config;
	// necessary settings.
	// config.calib_image_ = "../calib.bmp";
	config.bin_thresh_ = 32;
	config.calib_image_ = "";
	config.resolution_ = Size(368, 640);
	// optional settings
	config.roi_ = Rect(0, 0, 360, 640);
	// config.show_image_flag_ = true;
	config.show_image_flag_ = false;
	config.show_more_info_flag_ = true;
	config.valid_contour_max_ = 999;
	config.valid_contour_min_ = 111;

    // adaptive threshold;
    config.is_adaptive_threshold_ = true;
    config.adaptive_threshold_low_ = 10;
    config.adaptive_threshold_high_ = 80;
    config.adaptive_size_ = 7;              // block size. must be odd.
    config.adaptive_offset_ = 10;           // block offset. 

	AGV_System agv(config);
	agv.decode(src);
	agv.showResults();
}


int main(void){

#if 0
	Mat src=imread("/home/larrydong/Desktop/test1.bmp", 0);
	// Mat src = imread("../test/id_1_1.bmp", 0);
	// Mat src=imread("/home/larrydong/Desktop/id_2_200.bmp", 0);
	process(src);
	waitKey(1);
	waitKey(0);
	return 0;
#endif

    VideoCapture cap("/home/larry/Desktop/video.mp4");
    if(!cap.isOpened()){
        cout << "Video not found..." << endl;
        return -1;
    }
    Mat img;
    while(1){
        cap >> img;
        if(img.type()!=CV_8UC1){
            cvtColor(img, img, CV_BGR2GRAY);
        }
        cout << "Size:' " << img.size() << endl;
        imshow("video", img);
        process(img);
        waitKey(1);
        waitKey(0);
    }

    return 0;


	cout << "Using pictures from: '" << filePath << "' ." << endl;
	for (int i = 23; i < 200;) {
		cout << "Frame: " << i << endl;
		if (i < 0)
			i = 0;
		g_src = imread(filePath + to_string(i) + ".bmp", 0);
		imshow("src", g_src);

		if (g_src.empty()) {
			cout << endl << "---------------------------------" << endl;
			cout << "共找到" << i << "张图片。" << endl << endl;
			i = 0;
			continue;
		}

		process(g_src);
		int keyValue = waitKey(0);
		switch (keyValue) {
		case 'w': case 'a':
			cout << "返回上一张图片..." << endl;
			i--;
			break;
		case 'b':
			cout << "回到第0张图..." << endl;
			i = 0;
			break;
		case 'q':
			return 0;
		default:
			i++;
			break;
		}
	}

}

