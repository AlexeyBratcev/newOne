#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QWidget(parent),
    uiRegistration(new Ui::RegistrationWindow)
{
    uiRegistration->setupUi(this);
    this->setWindowTitle("Регистрация");
}

RegistrationWindow::~RegistrationWindow()
{
    delete uiRegistration;
}

void RegistrationWindow::on_pushButtonRegistration_clicked()
{
    emit register_button_clicked();
}

void RegistrationWindow::on_lineEditConfirm_textEdited(const QString &arg1)
{
   RegistrationWindow::confirmationOfPassword = arg1;
}

void RegistrationWindow::on_lineEditName_textEdited(const QString &arg1)
{
     RegistrationWindow::userName = arg1;
}

void RegistrationWindow::on_lineEditPassword_textEdited(const QString &arg1)
{
    RegistrationWindow::userPassword = arg1;
}

QString RegistrationWindow::getName()
{
    return RegistrationWindow::userName;
}

QString RegistrationWindow::getPassword()
{
    return RegistrationWindow::userPassword;
}

bool RegistrationWindow::checkPassword()
{
    return (confirmationOfPassword == userPassword);
}
