/********************************************************************************
** Form generated from reading UI file 'testableform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTABLEFORM_H
#define UI_TESTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestableForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *nextBtn;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *infoLabel;

    void setupUi(QWidget *TestableForm)
    {
        if (TestableForm->objectName().isEmpty())
            TestableForm->setObjectName(QStringLiteral("TestableForm"));
        TestableForm->resize(400, 300);
        gridLayout = new QGridLayout(TestableForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        nextBtn = new QPushButton(TestableForm);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));

        horizontalLayout->addWidget(nextBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        infoLabel = new QLabel(TestableForm);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(infoLabel);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(TestableForm);

        QMetaObject::connectSlotsByName(TestableForm);
    } // setupUi

    void retranslateUi(QWidget *TestableForm)
    {
        TestableForm->setWindowTitle(QApplication::translate("TestableForm", "Form", Q_NULLPTR));
        nextBtn->setText(QApplication::translate("TestableForm", "Next", Q_NULLPTR));
        infoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TestableForm: public Ui_TestableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTABLEFORM_H
