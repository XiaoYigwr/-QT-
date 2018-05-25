/********************************************************************************
** Form generated from reading UI file 'myplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPLAYER_H
#define UI_MYPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyPlayerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyPlayerClass)
    {
        if (MyPlayerClass->objectName().isEmpty())
            MyPlayerClass->setObjectName(QStringLiteral("MyPlayerClass"));
        MyPlayerClass->resize(600, 400);
        menuBar = new QMenuBar(MyPlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyPlayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyPlayerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyPlayerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyPlayerClass->setStatusBar(statusBar);

        retranslateUi(MyPlayerClass);

        QMetaObject::connectSlotsByName(MyPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyPlayerClass)
    {
        MyPlayerClass->setWindowTitle(QApplication::translate("MyPlayerClass", "MyPlayer", 0));
    } // retranslateUi

};

namespace Ui {
    class MyPlayerClass: public Ui_MyPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPLAYER_H
