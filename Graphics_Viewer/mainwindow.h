#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDropEvent>
#include <QFileInfo>
#include <QMimeData>
#include <QResizeEvent>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QDebug>

#include "qcustomgraphicseffect.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void dropEvent(QDropEvent * event);
    void dragEnterEvent(QDragEnterEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;

    QGraphicsScene scene;
};

#endif // MAINWINDOW_H
