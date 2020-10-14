
cmake_minimum_required(VERSION 3.1)
SET(CMAKE_CXX_FLAGS "-std=c++11")
PROJECT(AGV_test)

MESSAGE(STATUS "Build ${PROJECT_NAME}...")

find_package(OpenCV 3 REQUIRED)

ADD_EXECUTABLE(AGV_test demo.cpp)

INCLUDE_DIRECTORIES(
	/usr/local/include/opencv4 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES(AGV_test DMScanner100 opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs opencv_videoio dmtx pthread)
