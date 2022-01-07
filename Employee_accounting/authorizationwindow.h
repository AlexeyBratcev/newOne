#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QWidget>

namespace Ui {
class AuthorizationWindow;
}

class AuthorizationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();
    QString getLogin();
    QString getPassword();

signals:
    void login_button_clicked();
    void register_button_clicked();

private slots:
    void on_lineEditName_textEdited(const QString &arg1);

    void on_lineEditPassword_textEdited(const QString &arg1);

    void on_pushButtonIn_clicked();

    void on_pushButtonRegistration_clicked();



private:
    Ui::AuthorizationWindow *uiAuthorization;
    QString userName;
    QString userPassword;
};

#endif // AUTHORIZATIONWINDOW_H
