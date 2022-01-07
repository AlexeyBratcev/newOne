#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QtSql/QtSql>
#include "authorizationwindow.h"
#include "registrationwindow.h"
#include <QSqlTableModel>

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
    QString queryDB;
    QSqlDatabase mainWindowDataBase;
    int userCounter;
    bool loginSuccesfull;
    QSqlTableModel *model;
    QSqlQuery *queryDBEmployee;
    QSqlQuery *query2;
    int row;

private slots:
    void authorizeUser();
    void registerWindowShow();
    void registerUser();


    void on_pushButton_addEmployee_clicked();
    void on_pushButton_deleteEmployee_clicked();
    void on_pushButton_editEmployee_clicked();
    void on_tableView_main_clicked(const QModelIndex &index);
};
#endif // MAINWINDOW_H
