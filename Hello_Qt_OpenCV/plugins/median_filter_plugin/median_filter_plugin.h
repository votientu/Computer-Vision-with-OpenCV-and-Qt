#ifndef MEDIAN_FILTER_PLUGIN_H
#define MEDIAN_FILTER_PLUGIN_H

#include "median_filter_plugin_global.h"
#include "cvplugininterface.h"

class MEDIAN_FILTER_PLUGINSHARED_EXPORT Median_filter_plugin:
        public QObject, public CVPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.tientuvo.cvplugininterface")
    Q_INTERFACES(CVPluginInterface)
public:
    Median_filter_plugin();
    ~Median_filter_plugin();
    QString description();
    void processImage(const cv::Mat &inputImage,
                      cv::Mat &outputImage);
};

#endif // MEDIAN_FILTER_PLUGIN_H
