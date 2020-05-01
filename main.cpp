#include <opencv2/opencv.hpp>
#include "xinterface.hpp"
#include "imagemanipulator.hpp"
#include "jumplogic.hpp"


int main()
{
    XInterface xinterface(960, 250, 0, 270);

    cv::Mat screenshot;
    cv::namedWindow("preview", cv::WINDOW_NORMAL);

    while (true) {
        screenshot = xinterface.get_screenshot();
        Imagemanipulator::preprocess_image(screenshot);
        Imagemanipulator::mark_dino(screenshot);
        if (Jumplogic::should_jump(screenshot)) {
            xinterface.press_space();
        }
        cv::imshow("preview", screenshot);
        cv::waitKey(10);      
    }
}
