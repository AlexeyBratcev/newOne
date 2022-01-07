/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditConfirm;
    QPushButton *pushButtonRegistration;
    QLineEdit *lineEditPassword;
    QLineEdit *lineEditName;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName(QString::fromUtf8("RegistrationWindow"));
        RegistrationWindow->resize(400, 300);
        gridLayoutWidget = new QWidget(RegistrationWindow);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 281, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        lineEditConfirm = new QLineEdit(gridLayoutWidget);
        lineEditConfirm->setObjectName(QString::fromUtf8("lineEditConfirm"));

        gridLayout->addWidget(lineEditConfirm, 3, 2, 1, 1);

        pushButtonRegistration = new QPushButton(gridLayoutWidget);
        pushButtonRegistration->setObjectName(QString::fromUtf8("pushButtonRegistration"));

        gridLayout->addWidget(pushButtonRegistration, 4, 2, 1, 1);

        lineEditPassword = new QLineEdit(gridLayoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        gridLayout->addWidget(lineEditPassword, 2, 2, 1, 1);

        lineEditName = new QLineEdit(gridLayoutWidget);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 2, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);


        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QWidget *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("RegistrationWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\321\203\320\271\321\202\320\265\321\201\321\214:", nullptr));
        pushButtonRegistration->setText(QCoreApplication::translate("RegistrationWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("RegistrationWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265:", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrationWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        label_3->setText(QCoreApplication::translate("RegistrationWindow", "\320\230\320\274\321\217:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
