#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorizationwindow.h"
#include "registrationwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_main(new Ui::MainWindow)
{
    userCounter = 0;
    loginSuccesfull = false;

    connect(&uiAuthorization, SIGNAL(login_button_clicked()),
                this, SLOT(authorizeUser()));

    connect(&uiAuthorization,SIGNAL(destroyed()),
                this, SLOT(show()));

    connect(&uiAuthorization,SIGNAL(register_button_clicked()),
                this,SLOT(registerWindowShow()));

    connect(&uiRegistration,SIGNAL(register_button_clicked()),
                this,SLOT(registerUser()));

    connect(&uiRegistration,SIGNAL(destroyed()),
                &uiAuthorization, SLOT(show()));

    if(!connectionToDataBase())
        {
            qDebug() << "Ошибка подключения базы данных";
        }


    QSqlQuery query;

    queryDataBase = "CREATE TABLE userlist ( "
                         "number INTEGER PRIMARY KEY NOT NULL,"
                         "name VARCHAR(20), "
                         "pass VARCHAR(12), "
                         "xpos INTEGER, "
                         "ypos INTEGER, "
                         "width INTEGER, "
                         "length INTEGER );";

    if(!query.exec(queryDataBase))
        {
                qDebug() << "Невозможно сформировать таблицу" << query.lastError();
        }

    ui_main->setupUi(this);
}


MainWindow::~MainWindow()
{
    if(loginSuccesfull)
    {
        QString str_t = "UPDATE userlist "
                        "SET xpos = %2, ypos = %3, width = %4, length = %5 "
                        "WHERE name = '%1';";
        queryDataBase = str_t .arg(mainUserName)
                         .arg(this->x())
                         .arg(this->y())
                         .arg(this->width())
                         .arg(this->height());
        QSqlQuery query;
        if(!query.exec(queryDataBase))
        {
            qDebug() << "Unable to insert data"  << query.lastError() << " : " << query.lastQuery() ;
        }
    }
    mainWindowDataBase.removeDatabase("authorisation");
    qDebug() << "MainWindow Destroyed";
    delete ui_main;
    exit(0);
}




void MainWindow::authorizeUser()
{
    mainUserName = uiAuthorization.getLogin();
    mainUserPassword = uiAuthorization.getPassword();

    QString str_t = " SELECT * "
                    " FROM userlist "
                    " WHERE name = '%1'";

    QString username = "";
    QString userpass = "";

    int xPos = 0;
    int yPos = 0;

    int width = 0;
    int length = 0;

    queryDataBase = str_t.arg(mainUserName);

    QSqlQuery query;
    QSqlRecord rec;

    if(!query.exec(queryDataBase))
    {
        qDebug() << "Unable to execute query - exiting" << query.lastError() << " : " << query.lastQuery();
    }
    rec = query.record();
    query.next();
    userCounter = query.value(rec.indexOf("number")).toInt();
    username = query.value(rec.indexOf("name")).toString();
    userpass = query.value(rec.indexOf("pass")).toString();
    if(mainUserName != username || mainUserPassword != userpass || mainUserPassword == "")
    {
        qDebug() << "Password missmatch" << username << " " << userpass;
        loginSuccesfull = false;
    }
    else
    {
        loginSuccesfull = true;
        xPos = query.value(rec.indexOf("xpos")).toInt();
        yPos = query.value(rec.indexOf("ypos")).toInt();
        width = query.value(rec.indexOf("width")).toInt();
        length = query.value(rec.indexOf("length")).toInt();
        uiAuthorization.close();
        uiRegistration.close();
        this->setGeometry(xPos,yPos,width, length);
        this->setWindowTitle("Учет сотрудников");




        QString str_t2 = " SELECT * "
                         " FROM userlist ";
        queryDataBase = str_t2;
        QSqlQuery query2;
        query2.exec(queryDataBase);
        while (query2.next())
        {

             QString name = query2.value(2).toString();
             qDebug() << name;
        }
        this->show();
    }
}

void MainWindow::registerWindowShow()
{
    uiAuthorization.hide();
    uiRegistration.show();
}

void MainWindow::registerUser()
{
    if(uiRegistration.checkPassword())
        {
            QSqlQuery query;
            QSqlRecord rec;
            QString str_t = "SELECT COUNT(*) "
                            "FROM userlist;";
            queryDataBase = str_t;
            if(!query.exec(queryDataBase))
            {
                qDebug() << "Unable to get number " << query.lastError() << " : " << query.lastQuery();
                return;
            }
            else
            {
                query.next();
                rec = query.record();
                userCounter = rec.value(0).toInt();
                qDebug() << userCounter;
            }


            mainUserName = uiRegistration.getName();
            mainUserPassword = uiRegistration.getPassword();
            userCounter++;
            str_t = "INSERT INTO userlist(number, name, pass, xpos, ypos, width, length)"
                    "VALUES(%1, '%2', '%3', %4, %5, %6, %7);";
            queryDataBase = str_t .arg(userCounter)
                             .arg(mainUserName)
                             .arg(mainUserPassword)
                             .arg(0)
                             .arg(0)
                             .arg(800)
                             .arg(400);

            if(!query.exec(queryDataBase))
            {
                qDebug() << "Unable to insert data"  << query.lastError() << " : " << query.lastQuery();
            }
            else
            {
                uiRegistration.hide();
                uiAuthorization.show();
            }
        }
        else
        {
            qDebug() << "Confirm password coorectly";
        }
}

void MainWindow::display()
{
    uiAuthorization.show();
}

bool MainWindow::connectionToDataBase()
{
    mainWindowDataBase = QSqlDatabase::addDatabase("QSQLITE");
    mainWindowDataBase.setDatabaseName("authorisation");
    if(!mainWindowDataBase.open())
    {
        qDebug() << "Cannot open database: " << mainWindowDataBase.lastError();
        return false;
    }
    return true;
}












