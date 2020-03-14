#include <QString>
#include <QtTest>
#include <QDebug>

#include "pixelcounter.h"

class HelloTestTest : public QObject
{
    Q_OBJECT

public:
    HelloTestTest();

private Q_SLOTS:
    void testPixelCount();
};

HelloTestTest::HelloTestTest()
{
}

void HelloTestTest::testPixelCount()
{
    int width = 605, height = 403;
    QString frame = "bamboo_forest.jpg";
    PixelCounter c;
    QVERIFY2(c.countPixels(frame) == width*height, "Failure");
}

QTEST_APPLESS_MAIN(HelloTestTest)

#include "tst_hellotesttest.moc"
