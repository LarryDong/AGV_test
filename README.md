# AGV 测试程序



## 安装

1. 将 dmtx.so.zip 文件解压，并同 libAGV_api.so 一起拷贝到系统链接库的默认路径

   ```bash
   cp libAGV_api.so libdmtx.so* /usr/local/lib
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



## 04/17更新
1. 恢复解码限时功能(默认30ms)，以保证杂乱环境运行速度上限；
2. 恢复角度检测功能，能够检测任意角度二维码
3. 修复state的bug，能够用01正确显示某个码是否成功解出
3. 可修改参数：tag.h 中 timeout_ms 为二维码解码限制时间，对于理想情况下单个二维码解码可以稳定在20ms以下。
可调整参数，使得时间足够解出4个码为最佳，由此提高解码速度。
