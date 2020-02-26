/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(501, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        topLayout = new QHBoxLayout();
        topLayout->setSpacing(6);
        topLayout->setObjectName(QStringLiteral("topLayout"));
        inputImglabel = new QLabel(centralWidget);
        inputImglabel->setObjectName(QStringLiteral("inputImglabel"));

        topLayout->addWidget(inputImglabel);

        inputImgEdit = new QLineEdit(centralWidget);
        inputImgEdit->setObjectName(QStringLiteral("inputImgEdit"));

        topLayout->addWidget(inputImgEdit);

        inputImgButton = new QPushButton(centralWidget);
        inputImgButton->setObjectName(QStringLiteral("inputImgButton"));

        topLayout->addWidget(inputImgButton);


        gridLayout->addLayout(topLayout, 0, 0, 1, 1);

        centerLayout = new QVBoxLayout();
        centerLayout->setSpacing(6);
        centerLayout->setObjectName(QStringLiteral("centerLayout"));
        filterLabel = new QLabel(centralWidget);
        filterLabel->setObjectName(QStringLiteral("filterLabel"));

        centerLayout->addWidget(filterLabel);

        filtersList = new QListWidget(centralWidget);
        filtersList->setObjectName(QStringLiteral("filtersList"));

        centerLayout->addWidget(filtersList);


        gridLayout->addLayout(centerLayout, 1, 0, 1, 1);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setSpacing(6);
        bottomLayout->setObjectName(QStringLiteral("bottomLayout"));
        helpButton = new QPushButton(centralWidget);
        helpButton->setObjectName(QStringLiteral("helpButton"));

        bottomLayout->addWidget(helpButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomLayout->addItem(horizontalSpacer);

        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));

        bottomLayout->addWidget(filterButton);


        gridLayout->addLayout(bottomLayout, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        inputImglabel->setText(QApplication::translate("MainWindow", "Input Image", Q_NULLPTR));
        inputImgButton->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        filterLabel->setText(QApplication::translate("MainWindow", "Filter Plugins", Q_NULLPTR));
        helpButton->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        filterButton->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
