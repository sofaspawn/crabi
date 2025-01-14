#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input video file>\n", argv[0]);
        return -1;
    }

    const char *filename = argv[1];
    cv::VideoCapture cap(filename);

    if (!cap.isOpened()) {
        printf("Could not open video file: %s\n", filename);
        return -1;
    }

    cv::Mat frame;
    int frameNumber = 0;

    while (true) {
        cap >> frame;  // Capture frame
        if (frame.empty()) break;

        char outputFilename[256];
        snprintf(outputFilename, sizeof(outputFilename), "frame_%04d.jpg", frameNumber);
        cv::imwrite(outputFilename, frame);

        printf("Saved %s\n", outputFilename);
        frameNumber++;
    }

    cap.release();
    return 0;
}

