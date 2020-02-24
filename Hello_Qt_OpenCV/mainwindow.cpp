#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_inputPushButton_pressed()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Open Input Image",
                                                    QDir::currentPath(),
                                                    "Images (*.jpg *.png *.bmp)");
    if(QFile::exists(filename))
        ui->inputLineEdit->setText(filename);
}

void MainWindow::on_outputPushButton_pressed()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Open Output Image",
                                                    QDir::currentPath(),
                                                    "Images (*.jpg *.png *.bmp)");
    if(QFile::exists(filename)) {
        ui->outputLineEdit->setText(filename);
        using namespace cv;
        Mat inpImg, outImg;
        inpImg = imread(ui->inputLineEdit->text().toStdString());
        if (ui->medianBlurRadioButton->isChecked())
            cv::medianBlur(inpImg, outImg, 5);
        else if (ui->gaussianBlurRadioButton->isChecked())
            cv::GaussianBlur(inpImg, outImg, Size(5, 5), 1.25);
        imwrite(filename.toStdString(), outImg);
        if (ui->displayImageCheckBox->isChecked())
            imshow("Output Image", outImg);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int result = QMessageBox::warning(this,
                                      "Exit",
                                      "Are you sure you want to close this program?",
                                      QMessageBox::Yes,
                                      QMessageBox::No);
    if (result == QMessageBox::Yes) {
        saveSettings();
        event->accept();
    }
    else
        event->ignore();
}

void MainWindow::loadSettings()
{
    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
    ui->inputLineEdit->setText(settings.value("inputLineEdit", "")
                               .toString());
    ui->outputLineEdit->setText(settings.value("outputLineEdit", "")
                                .toString());
    ui->medianBlurRadioButton->setChecked(
                settings.value("medianBlurRadioButton", true).toBool());
    ui->gaussianBlurRadioButton->setChecked(
                settings.value("gaussianBlurRadioButton", false).toBool());
    ui->displayImageCheckBox->setChecked(
                settings.value("displayImageCheckBox", false).toBool());
}

void MainWindow::saveSettings()
{
    QSettings settings("Packt",
                       "Hello_OpenCV_Qt",
                       this);
    settings.setValue("inputLineEdit",
                      ui->inputLineEdit->text());
    settings.setValue("outputLineEdit",
                      ui->outputLineEdit->text());
    settings.setValue("medianBlurRadioButton",
                      ui->medianBlurRadioButton->isChecked());
    settings.setValue("gaussianBlurRadioButton",
                      ui->gaussianBlurRadioButton->isChecked());
    settings.setValue("displayImageCheckBox",
                      ui->displayImageCheckBox->isChecked());
}
