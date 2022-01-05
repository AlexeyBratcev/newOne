#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtSql/QtSql>
#include "authorizationwindow.h"
#include "registrationwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display();
    bool connectionToDataBase();

private:
    Ui::MainWindow *ui_main;
    AuthorizationWindow uiAuthorization;
    RegistrationWindow uiRegistration;
    QString mainUserName;
    QString mainUserPassword;
    QString queryDataBase;
    QSqlDatabase mainWindowDataBase;
    int userCounter;
    bool loginSuccesfull;

private slots:
    void authorizeUser();
    void registerWindowShow();
    void registerUser();


};
#endif // MAINWINDOW_H
