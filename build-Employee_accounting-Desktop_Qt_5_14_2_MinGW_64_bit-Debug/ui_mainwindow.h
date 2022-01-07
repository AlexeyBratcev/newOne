/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView_main;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_deleteEmployee;
    QPushButton *pushButton_editEmployee;
    QPushButton *pushButton_addEmployee;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1022, 637);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(19, 9, 821, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView_main = new QTableView(gridLayoutWidget);
        tableView_main->setObjectName(QString::fromUtf8("tableView_main"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView_main->sizePolicy().hasHeightForWidth());
        tableView_main->setSizePolicy(sizePolicy);

        gridLayout->addWidget(tableView_main, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(870, 10, 131, 531));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_deleteEmployee = new QPushButton(gridLayoutWidget_2);
        pushButton_deleteEmployee->setObjectName(QString::fromUtf8("pushButton_deleteEmployee"));
        pushButton_deleteEmployee->setAutoRepeatDelay(300);

        gridLayout_2->addWidget(pushButton_deleteEmployee, 3, 0, 1, 1);

        pushButton_editEmployee = new QPushButton(gridLayoutWidget_2);
        pushButton_editEmployee->setObjectName(QString::fromUtf8("pushButton_editEmployee"));
        pushButton_editEmployee->setAutoRepeatDelay(300);

        gridLayout_2->addWidget(pushButton_editEmployee, 2, 0, 1, 1);

        pushButton_addEmployee = new QPushButton(gridLayoutWidget_2);
        pushButton_addEmployee->setObjectName(QString::fromUtf8("pushButton_addEmployee"));
        pushButton_addEmployee->setAutoRepeatDelay(300);

        gridLayout_2->addWidget(pushButton_addEmployee, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1022, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\243\321\207\320\265\321\202 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\276\320\262", nullptr));
        pushButton_deleteEmployee->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_editEmployee->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        pushButton_addEmployee->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
