#include "imagemanipulator.hpp"
#include <opencv2/opencv.hpp>


void Imagemanipulator::preprocess_image(cv::Mat& img) {
    cv::cvtColor(img, img, cv::COLOR_RGB2GRAY);
    img = img > 128;
}

void Imagemanipulator::mark_dino(cv::Mat& img) {
    cv::Mat result;
    int result_cols =  img.cols - dino_template.cols + 1;
    int result_rows = img.rows - dino_template.rows + 1;
    result.create(result_rows, result_cols, CV_32FC1);

    cv::matchTemplate(img, dino_template, result, 0);
    cv::normalize(result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
    double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;

    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());
    cv::rectangle( img, minLoc, cv::Point( minLoc.x + dino_template.cols , minLoc.y + dino_template.rows ), cv::Scalar::all(0), 2, 8, 0 );
    cv::putText(img, "dino", minLoc, cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar::all(0), 2);
}

bool Imagemanipulator::detect_obstacle(cv::Mat& img, cv::Point p1, cv::Point p2) {
    double minVal; 
    double maxVal; 
    cv::minMaxLoc(img(cv::Rect(p1, p2)), &minVal, &maxVal);
    if (minVal < 128) {
        cv::rectangle(img, p1, p2, cv::Scalar::all(0), 10, 8, 0 );
        return true;
    }
    else {
        cv::rectangle(img, p1, p2, cv::Scalar::all(0), 2, 8, 0 );
        return false;
    }
}

cv::Mat Imagemanipulator::dino_template = cv::imread("dino.png", cv::IMREAD_GRAYSCALE);
