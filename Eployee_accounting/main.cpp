#include "mainwindow.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << "!!!!!!!!!!!!!!!!!!!!!!";
    QApplication a(argc, argv);
    MainWindow win;

    win.display();
    return a.exec();
}
