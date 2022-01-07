#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"

AuthorizationWindow::AuthorizationWindow(QWidget *parent) :
    QWidget(parent),
    uiAuthorization(new Ui::AuthorizationWindow)
{
    uiAuthorization->setupUi(this);
    this->setWindowTitle("Авторизация");
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete uiAuthorization;
}

void AuthorizationWindow::on_lineEditName_textEdited(const QString &arg1)
{
    AuthorizationWindow::userName = arg1;
}

void AuthorizationWindow::on_lineEditPassword_textEdited(const QString &arg1)
{
    AuthorizationWindow::userPassword = arg1;
}

void AuthorizationWindow::on_pushButtonIn_clicked()
{
    emit login_button_clicked();
}

void AuthorizationWindow::on_pushButtonRegistration_clicked()
{
    emit register_button_clicked();
}

QString AuthorizationWindow::getLogin()
{
    return AuthorizationWindow::userName;
}

QString AuthorizationWindow::getPassword()
{
    return AuthorizationWindow::userPassword;
}

