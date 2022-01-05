#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QWidget>

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

    QString getName();
    QString getPassword();
    bool checkPassword();

signals:
    void register_button_clicked();


private slots:

    void on_pushButtonRegistration_clicked();

    void on_lineEditConfirm_textEdited(const QString &arg1);

    void on_lineEditName_textEdited(const QString &arg1);

    void on_lineEditPassword_textEdited(const QString &arg1);

private:
    Ui::RegistrationWindow *uiRegistration;
    QString userName;
    QString userPassword;
    QString confirmationOfPassword;
};

#endif // REGISTRATIONWINDOW_H
