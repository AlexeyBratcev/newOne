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
            qDebug() << "Database connection error";
        }


    QSqlQuery query;

    queryDB = "CREATE TABLE userlist ( "
                         "number INTEGER PRIMARY KEY NOT NULL,"
                         "name VARCHAR(20), "
                         "pass VARCHAR(12), "
                         "xpos INTEGER, "
                         "ypos INTEGER, "
                         "width INTEGER, "
                         "length INTEGER );";

    if(!query.exec(queryDB))
        {
            qDebug() << "unable to create a table at userlist" << query.lastError();
        }

    ui_main->setupUi(this);

    queryDBEmployee = new QSqlQuery(mainWindowDataBase);
    QString queryDataBase;
    queryDataBase = "CREATE TABLE employeeslist( "
                         "number INTEGER PRIMARY KEY AUTOINCREMENT,"
                         "name VARCHAR(20), "
                         "lastname VARCHAR(20), "
                         "patronymic VARCHAR(20),"
                         "dateofbirth DATA );";


    if (queryDBEmployee->exec(queryDataBase))
    {
        qDebug() << "table employeeslist is created";
    }
    else
    {
        qDebug() << "table employeeslist can't be created" << queryDBEmployee->lastError() << " : " << queryDBEmployee->lastQuery() ;
    }

    model = new QSqlTableModel(this, mainWindowDataBase);
    model->setTable("employeeslist");
    model->select();

    ui_main->tableView_main->setModel(model);
    // ui_main->tableView_main->setColumnHidden(0, true);

}

MainWindow::~MainWindow()
{
    if(loginSuccesfull)
    {
        QString str_t = "UPDATE userlist "      // сохранение геометрии окна пользователя
                        "SET xpos = %2, ypos = %3, width = %4, length = %5 "
                        "WHERE name = '%1';";
        queryDB = str_t .arg(mainUserName)
                         .arg(this->x())
                         .arg(this->y())
                         .arg(this->width())
                         .arg(this->height());
        QSqlQuery query;
        if(!query.exec(queryDB))
        {
            qDebug() << "Unable to insert data"  << query.lastError() << " : " << query.lastQuery() ;
        }
    }
    mainWindowDataBase.removeDatabase("mainWindowDataBase");
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

    queryDB = str_t.arg(mainUserName);

    QSqlQuery query;
    QSqlRecord rec;

    if(!query.exec(queryDB))
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
            queryDB = str_t;
            if(!query.exec(queryDB))
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
            queryDB = str_t .arg(userCounter)
                             .arg(mainUserName)
                             .arg(mainUserPassword)
                             .arg(0)
                             .arg(0)
                             .arg(1200)
                             .arg(800);

            if(!query.exec(queryDB))
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
    mainWindowDataBase.setDatabaseName("D:/project/dataBaseEmployee.db");
    if(!mainWindowDataBase.open())
    {
        qDebug() << "Can't open database: " << mainWindowDataBase.lastError();
        return false;
    }
    return true;
}




void MainWindow::on_pushButton_addEmployee_clicked()
{
   model->insertRow(model->rowCount());
}

void MainWindow::on_pushButton_deleteEmployee_clicked()
{
    model->removeRow(row);
    model->select();
}

void MainWindow::on_pushButton_editEmployee_clicked()
{
model->select();
}

void MainWindow::on_tableView_main_clicked(const QModelIndex &index)
{
    row = index.row();
}
