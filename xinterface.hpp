#include <opencv2/opencv.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>


struct XInterface
{
    XInterface(int _width=0, int _height=0, int _x=0, int _y = 0);
    cv::Mat get_screenshot();
    void press_space();
    ~XInterface();

    Display* display;
    Window root;
    int width, height, x, y;
    XImage* screenshot;
};
