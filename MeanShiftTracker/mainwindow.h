#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QPixmap>

#include "qcvmeanshiftthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QCvMeanShiftThread *meanshift;
    QGraphicsPixmapItem pixmap;

private slots:
    void onRubberBandChanged(QRect rect, QPointF frScn, QPointF toScn);
    void onNewFrame(QPixmap newFrm);
};

#endif // MAINWINDOW_H
