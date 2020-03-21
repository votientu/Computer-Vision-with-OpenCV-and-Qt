#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "qimageprocessor.h"
#include "qimageviewer.h"

int main(int argc, char *argv[])
{ 
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<QImageProcessor>("com.tientuvo.classes",
                                     1, 0, "ImageProccessor");
    qmlRegisterType<QImageViewer>("com.tientuvo.classes",
                                  1, 0, "ImageViewer");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
