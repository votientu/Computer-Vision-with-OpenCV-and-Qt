#include "videoprocessor.h"

VideoProcessor::VideoProcessor(QObject *parent) : QObject(parent)
{

}

void VideoProcessor::startVideo()
{
    using namespace cv;
    VideoCapture camera(0);
    Mat inFrame, outFrame;
    stopped = false;
    while(camera.isOpened() && !stopped)
    {
        camera >> inFrame;
        if (inFrame.empty())
            continue;

        // Invert every bit of inFrame to outFrame
        bitwise_not(inFrame, outFrame);

        emit inDisplay(QPixmap::fromImage(
                           QImage(inFrame.data,
                                  inFrame.cols,
                                  inFrame.rows,
                                  inFrame.step,
                                  QImage::Format_RGB888)
                           .rgbSwapped()));

        emit outDisplay(QPixmap::fromImage(
                            QImage(outFrame.data,
                                   outFrame.cols,
                                   outFrame.rows,
                                   outFrame.step,
                                   QImage::Format_RGB888)
                            .rgbSwapped()));
    }
}

void VideoProcessor::stopVideo()
{
    stopped = true;
}
