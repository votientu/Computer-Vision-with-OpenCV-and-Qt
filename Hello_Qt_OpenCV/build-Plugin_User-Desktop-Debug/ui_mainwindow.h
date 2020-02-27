/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *topLayout;
    QLabel *inputImglabel;
    QLineEdit *inputImgEdit;
    QPushButton *inputImgButton;
    QVBoxLayout *centerLayout;
    QLabel *filterLabel;
    QListWidget *filtersList;
    QHBoxLayout *bottomLayout;
    QPushButton *helpButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *filterButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(501, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topLayout = new QHBoxLayout();
        topLayout->setSpacing(6);
        topLayout->setObjectName(QString::fromUtf8("topLayout"));
        inputImglabel = new QLabel(centralWidget);
        inputImglabel->setObjectName(QString::fromUtf8("inputImglabel"));

        topLayout->addWidget(inputImglabel);

        inputImgEdit = new QLineEdit(centralWidget);
        inputImgEdit->setObjectName(QString::fromUtf8("inputImgEdit"));

        topLayout->addWidget(inputImgEdit);

        inputImgButton = new QPushButton(centralWidget);
        inputImgButton->setObjectName(QString::fromUtf8("inputImgButton"));

        topLayout->addWidget(inputImgButton);


        gridLayout->addLayout(topLayout, 0, 0, 1, 1);

        centerLayout = new QVBoxLayout();
        centerLayout->setSpacing(6);
        centerLayout->setObjectName(QString::fromUtf8("centerLayout"));
        filterLabel = new QLabel(centralWidget);
        filterLabel->setObjectName(QString::fromUtf8("filterLabel"));

        centerLayout->addWidget(filterLabel);

        filtersList = new QListWidget(centralWidget);
        filtersList->setObjectName(QString::fromUtf8("filtersList"));

        centerLayout->addWidget(filtersList);


        gridLayout->addLayout(centerLayout, 1, 0, 1, 1);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setSpacing(6);
        bottomLayout->setObjectName(QString::fromUtf8("bottomLayout"));
        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        bottomLayout->addWidget(helpButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomLayout->addItem(horizontalSpacer);

        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QString::fromUtf8("filterButton"));

        bottomLayout->addWidget(filterButton);


        gridLayout->addLayout(bottomLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        inputImglabel->setText(QApplication::translate("MainWindow", "Input Image", nullptr));
        inputImgButton->setText(QApplication::translate("MainWindow", "Browse", nullptr));
        filterLabel->setText(QApplication::translate("MainWindow", "Filter Plugins", nullptr));
        helpButton->setText(QApplication::translate("MainWindow", "Help", nullptr));
        filterButton->setText(QApplication::translate("MainWindow", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
