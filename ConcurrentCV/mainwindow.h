#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfoList>
#include <QFileDialog>
#include <QElapsedTimer>
#include <QMessageBox>
#include <QFuture>
#include <QtConcurrent>
#include <QFutureWatcher>
#include <opencv2/opencv.hpp>

void addDateTime(QFileInfo &info);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loopBtn_pressed();

    void on_concurrentBtn_pressed();

private:
    Ui::MainWindow *ui;

    QFileInfoList getImageInFolder();
};

#endif // MAINWINDOW_H
