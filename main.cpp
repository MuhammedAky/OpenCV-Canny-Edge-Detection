#include <opencv4/opencv2/opencv.hpp>
#include <chrono>
#include <cstdlib>
using namespace cv;

int main(int argc, char *argv[]) {
    Mat image;

    namedWindow("main");
    int cam = atoi(argv[1]);
    int fps = atoi(argv[2]);
    int delay  1000 / fps;
    VideoCapture cap(cam);
    cap.set(CAP_PROP_FRAME_HEIGHT, 720);
    cap.set(CAP_PROP_FRAME_WIDTH, 1280);

    if (!cap.isOpened())
        return -1;

    char c;

    while (1) {
        fps = cap.get(CAP_PROP_FPS)
        cap >> image;
        cvtColor(image, image, COLOR_BGR2GRAY);
        GaussianBlue(image, image, Size(3,3), 0);
        Canny(image, image, 100, 200, 3, false);
        imshow("main", image);
        c = (char)waitKey(delay);

        if (c == 27)
            break;
    }

    cap.release();
}