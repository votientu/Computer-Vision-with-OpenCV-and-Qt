import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtMultimedia 5.12

import com.tientuvo.classes 1.0

ApplicationWindow {
    visible: true
    width: 300
    height: 500
    title: qsTr("CvQml")

    Camera
    {
        id: camera
        imageCapture
        {
            onImageSaved:
            {
                imgProcessor.processImage(path)
            }
        }
    }

    ImageProccessor
    {
        id: imgProcessor
        onImageProcessed:
        {
            imgViewer.setImage(image);
            imageDrawer.open()
        }
    }

    Drawer
    {
        id: imageDrawer
        width: parent.width
        height: parent.height
        ImageViewer
        {
            id: imgViewer
            anchors.fill: parent
            Label
            {
                text: "Swipe from right to left<br>to return to capture mode!"
                color: "red"
            }
        }
    }

    VideoOutput
    {
        source: camera
        anchors.fill: parent
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                camera.imageCapture.capture()
            }
        }
        Label
        {
            text: "Touch the screen to take a photo<br>and process it using OpenCV!"
            color: "red"
        }
    }
}
