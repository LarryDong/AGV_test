# AGV 测试程序



## 安装

1. 将 libAGV_api.so 拷贝到系统链接库的默认路径

   ```bash
   cp libAGV_api.so /usr/local/lib
   ```

## 代码运行

1. 需包含AGV_api.h头文件，以及include下全部头文件
2. 参考CMakeLists.txt文件进行配置
3. 参考demo.cpp编写测试：配置、解码、显示结果
4. 运行输出：整个二维码贴纸的标签、中心位置、旋转角度、状态(4位表示具体小二维码是否成功解码)、耗时


## 代码参数配置

所有代码的参数配置通过 AGV_System_Config 实现。

必须配置的参数有：
1. calib_image_：亮度校准图片，需指定文件路径
2. resolution_：图像分辨率

可选配置的参数有：
1. roi_，图像区域，可以选择一部分区域，默认为图像中心的正方形；
2. show_image_flag_，设置为true后进行一些图片显示，默认为false；**注意：只能在树莓派屏幕的情况下启动显示**
