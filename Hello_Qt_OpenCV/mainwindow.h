#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSettings>

#include "opencv2/opencv.hpp"

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
    void on_inputPushButton_pressed();

    void on_outputPushButton_pressed();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    void loadSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H
