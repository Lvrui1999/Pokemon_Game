/********************************************************************************
** Form generated from reading UI file 'userinit.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINIT_H
#define UI_USERINIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserInit
{
public:
    QLabel *label;
    QPushButton *View_Person;
    QListWidget *listWidget;
    QPushButton *Battle;
    QPushButton *EXit;
    QPushButton *ReFresh;
    QListWidget *All_User;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *UserInit)
    {
        if (UserInit->objectName().isEmpty())
            UserInit->setObjectName(QString::fromUtf8("UserInit"));
        UserInit->resize(731, 531);
        label = new QLabel(UserInit);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 30, 191, 81));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        View_Person = new QPushButton(UserInit);
        View_Person->setObjectName(QString::fromUtf8("View_Person"));
        View_Person->setGeometry(QRect(130, 440, 93, 28));
        listWidget = new QListWidget(UserInit);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(90, 160, 201, 251));
        Battle = new QPushButton(UserInit);
        Battle->setObjectName(QString::fromUtf8("Battle"));
        Battle->setGeometry(QRect(360, 440, 93, 28));
        EXit = new QPushButton(UserInit);
        EXit->setObjectName(QString::fromUtf8("EXit"));
        EXit->setGeometry(QRect(480, 440, 93, 28));
        ReFresh = new QPushButton(UserInit);
        ReFresh->setObjectName(QString::fromUtf8("ReFresh"));
        ReFresh->setGeometry(QRect(70, 440, 31, 28));
        All_User = new QListWidget(UserInit);
        All_User->setObjectName(QString::fromUtf8("All_User"));
        All_User->setGeometry(QRect(430, 150, 241, 271));
        label_2 = new QLabel(UserInit);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 110, 91, 20));
        label_3 = new QLabel(UserInit);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(520, 110, 72, 15));
        pushButton = new QPushButton(UserInit);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 440, 93, 28));

        retranslateUi(UserInit);

        QMetaObject::connectSlotsByName(UserInit);
    } // setupUi

    void retranslateUi(QWidget *UserInit)
    {
        UserInit->setWindowTitle(QCoreApplication::translate("UserInit", "Form", nullptr));
        label->setText(QCoreApplication::translate("UserInit", "UserInterface", nullptr));
        View_Person->setText(QCoreApplication::translate("UserInit", "View_L", nullptr));
        Battle->setText(QCoreApplication::translate("UserInit", "Battle", nullptr));
        EXit->setText(QCoreApplication::translate("UserInit", "Exit", nullptr));
        ReFresh->setText(QCoreApplication::translate("UserInit", "Re", nullptr));
        label_2->setText(QCoreApplication::translate("UserInit", "Online User", nullptr));
        label_3->setText(QCoreApplication::translate("UserInit", "All User", nullptr));
        pushButton->setText(QCoreApplication::translate("UserInit", "View_R", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserInit: public Ui_UserInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINIT_H
