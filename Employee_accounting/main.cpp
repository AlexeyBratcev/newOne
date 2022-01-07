#include "mainwindow.h"
#include <QDebug>

#include <QApplication>

int main(int argc, char *argv[])
{
    qDebug() << "Let's start";
    QApplication a(argc, argv);
    MainWindow w;

    w.display();
    return a.exec();
}
