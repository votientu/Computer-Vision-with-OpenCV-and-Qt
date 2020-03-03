#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAcceptDrops(true);
    ui->graphicsView->setAcceptDrops(false);
    ui->graphicsView->setScene(&scene);

    QPushButton *button = new QPushButton(Q_NULLPTR);
    connect(button, SIGNAL(pressed()), this, SLOT(onAction()));
    button->setText(tr("Do it!"));
    QGraphicsProxyWidget* proxy = scene.addWidget(button);
    proxy->setGeometry(QRectF(-200.0, -200, 400, 100.0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    QStringList acceptedFileTypes;
    acceptedFileTypes.append("jpg");
    acceptedFileTypes.append("png");
    acceptedFileTypes.append("bmp");

    if (event->mimeData()->hasUrls() && event->mimeData()->urls().count() == 1)
    {
        QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
        if (acceptedFileTypes.contains(file.suffix().toLower()))
            event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QFileInfo file(event->mimeData()->urls().at(0).toLocalFile());
    QPixmap pixmap;
    if (pixmap.load(file.absoluteFilePath()))
    {
        scene.clear();

        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        item->setGraphicsEffect(new QCustomGraphicsEffect(this));
        scene.addItem(item);
    }
    else
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("The image file cannot be read!"));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    /*
    QPixmap pixmap = scene.items().last();
    if (!pixmap.isNull())
        scene-> .scaled(scene->width()-5,
                                           scene->height()-5,
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation));
    */
}
