#include <opencv2/opencv.hpp>


struct Imagemanipulator
{
    static void preprocess_image(cv::Mat& img);
    static void mark_dino(cv::Mat& img);
    static bool detect_obstacle(cv::Mat& img, cv::Point p1, cv::Point p2);

    static cv::Mat dino_template;
};
