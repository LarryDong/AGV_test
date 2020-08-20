
#include "AGV_api.h"

int main(void){
	
	Mat src=imread("dm.bmp", 0);	

	AGV_System_Config config;	// 进行AGV相关配置
	// necessary settings. 以下配置是必须的，包括：校准图片路径，图片分辨率
	// config.calib_image_ = "/home/pi/codeGit/AGV_code/API/calib.bmp";
	config.calib_image_ = "";
	config.resolution_ = Size(1280, 1024);
	// optional settings. 以下配置是可选，包括：区域大小，以及是否显示图片
	config.roi_ = Rect(100, 0, 1000, 1000);
	config.show_image_flag_ = false;		// 只有在连接屏幕时才可以设置为true。否则会崩溃。
	config.bin_thresh_ = 30;

	AGV_System agv(config);		// 使用配置进行系统的初始化
	agv.decode(src);			// 解码主要函数。输入图片
	agv.showResults();			// 输出解码结果

	waitKey(1);
	waitKey(0);
	return 0;
}
