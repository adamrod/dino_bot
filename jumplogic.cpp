#include <opencv2/opencv.hpp>
#include "imagemanipulator.hpp"
#include "jumplogic.hpp"


bool Jumplogic::should_jump(cv::Mat& img) {
    // TODO
    bool obstacle1 = Imagemanipulator::detect_obstacle(img, cv::Point(910, 170), cv::Point(950, 200));
    bool obstacle2 = Imagemanipulator::detect_obstacle(img, cv::Point(160, 170), cv::Point(200, 200));
    return obstacle2;
}
