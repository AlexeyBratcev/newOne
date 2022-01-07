/********************************************************************************
** Form generated from reading UI file 'authorizationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATIONWINDOW_H
#define UI_AUTHORIZATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorizationWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonRegistration;
    QPushButton *pushButtonIn;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPassword;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QWidget *AuthorizationWindow)
    {
        if (AuthorizationWindow->objectName().isEmpty())
            AuthorizationWindow->setObjectName(QString::fromUtf8("AuthorizationWindow"));
        AuthorizationWindow->resize(286, 260);
        gridLayoutWidget = new QWidget(AuthorizationWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 221, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonRegistration = new QPushButton(gridLayoutWidget);
        pushButtonRegistration->setObjectName(QString::fromUtf8("pushButtonRegistration"));

        gridLayout->addWidget(pushButtonRegistration, 4, 2, 1, 1);

        pushButtonIn = new QPushButton(gridLayoutWidget);
        pushButtonIn->setObjectName(QString::fromUtf8("pushButtonIn"));

        gridLayout->addWidget(pushButtonIn, 3, 2, 1, 1);

        lineEditName = new QLineEdit(gridLayoutWidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 2, 1, 1);

        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        gridLayout->addWidget(lineEditPassword, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);


        retranslateUi(AuthorizationWindow);

        QMetaObject::connectSlotsByName(AuthorizationWindow);
    } // setupUi

    void retranslateUi(QWidget *AuthorizationWindow)
    {
        AuthorizationWindow->setWindowTitle(QCoreApplication::translate("AuthorizationWindow", "Form", nullptr));
        pushButtonRegistration->setText(QCoreApplication::translate("AuthorizationWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        pushButtonIn->setText(QCoreApplication::translate("AuthorizationWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("AuthorizationWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\270 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("AuthorizationWindow", "\320\230\320\274\321\217:", nullptr));
        label_3->setText(QCoreApplication::translate("AuthorizationWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorizationWindow: public Ui_AuthorizationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATIONWINDOW_H
