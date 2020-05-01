#include "xinterface.hpp"
#include <X11/extensions/XTest.h>
#include <chrono>
#include <thread>


XInterface::XInterface(int _width, int _height, int _x, int _y) {
    display = XOpenDisplay(nullptr);
    if (_width == 0 or _height == 0) {
        Screen* screen = DefaultScreenOfDisplay(display);
        width = screen->width;
        height = screen->height;
    } else {
        width = _width;
        height = _height;
    }
    x = _x;
    y = _y;
    root = DefaultRootWindow(display); 
}

cv::Mat XInterface::get_screenshot() {
    screenshot = XGetImage(display, root, x, y, width, height, AllPlanes, ZPixmap);
    return cv::Mat(height, width, CV_8UC4, screenshot->data);
}

void XInterface::press_space() {
    Display* d = XOpenDisplay(nullptr);
    XTestFakeKeyEvent(d, 65, True,  CurrentTime);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    XTestFakeKeyEvent(d, 65, False, CurrentTime);
    XCloseDisplay(d);
}

XInterface::~XInterface() {
    XCloseDisplay(display);
    XDestroyImage(screenshot);
}
