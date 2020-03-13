#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QFileInfoList MainWindow::getImageInFolder()
{
    QDir dir(QFileDialog::getExistingDirectory(this, tr("Open Images Folder")));
    return dir.entryInfoList(QStringList() << "*.jpg" << "*.png",
                             QDir::NoDotAndDotDot | QDir::Files,
                             QDir::Name);
}

void addDateTime(QFileInfo &info)
{
    using namespace cv;
    Mat image = imread(info.absoluteFilePath().toStdString());
    if (!image.empty())
    {
        QString dateTime = info.created().toString();
        putText(image,
                dateTime.toStdString(),
                Point(30, 30),      // 25 pixels offset from the corner
                FONT_HERSHEY_PLAIN,
                1.0,
                Scalar(0, 0, 255)); // red
        imwrite(info.absoluteFilePath().toStdString(), image);
    }
}

void MainWindow::on_loopBtn_pressed()
{
    QFileInfoList list = getImageInFolder();

    QElapsedTimer elapsedTimer;
    elapsedTimer.start();

    ui->progressBar->setRange(0, list.count() - 1);
    for (int i = 0; i < list.count(); i++)
    {
        addDateTime(list[i]);
        ui->progressBar->setValue(i);
        qApp->processEvents();
    }

    qint64 e = elapsedTimer.elapsed();

    QMessageBox::information(this, tr("Done"),
                             QString(tr("Processed %1 images in %2 milliseconds"))
                             .arg(list.count())
                             .arg(e));
}

void MainWindow::on_concurrentBtn_pressed()
{
    QFileInfoList list = getImageInFolder();

    QElapsedTimer elapsedTimer;
    elapsedTimer.start();

    QFuture<void> future = QtConcurrent::map(list, addDateTime);
    QFutureWatcher<void> *watcher = new QFutureWatcher<void>(this);
    connect(watcher, SIGNAL(progressRangeChanged(int,int)),
            ui->progressBar, SLOT(setRange(int,int)));
    connect(watcher, SIGNAL(progressValueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
    connect(watcher, &QFutureWatcher<void>::finished,
            [=]()
    {
        qint64 e = elapsedTimer.elapsed();
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("Processed %1 images in %2 milliseconds"))
                                 .arg(list.count())
                                 .arg(e));
    });
    connect(watcher, SIGNAL(finished()), watcher, SLOT(deleteLater()));

    watcher->setFuture(future);
}
