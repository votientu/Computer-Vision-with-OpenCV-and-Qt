#include "gaussian_filter_plugin.h"

Gaussian_filter_plugin::Gaussian_filter_plugin()
{}

Gaussian_filter_plugin::~Gaussian_filter_plugin()
{}

QString Gaussian_filter_plugin::description()
{
    return "This plugin applies gaussian blur filters to any image."
            " This plugin's goal is to make us more familiar with the"
            " concept of plugins in general.";
}

void Gaussian_filter_plugin::processImage(const cv::Mat &inputImage,
                                          cv::Mat &outputImage)
{
    cv::GaussianBlur(inputImage, outputImage, cv::Size(5, 5), 1.25);
}

