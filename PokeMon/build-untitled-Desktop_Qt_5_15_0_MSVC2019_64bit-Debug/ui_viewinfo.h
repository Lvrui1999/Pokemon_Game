/********************************************************************************
** Form generated from reading UI file 'viewinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWINFO_H
#define UI_VIEWINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewInfo
{
public:
    QLabel *Uname;
    QLabel *WinAndLose;
    QLabel *JZ_1;
    QLabel *JZ_2;
    QLabel *Pic;
    QListWidget *PList;

    void setupUi(QWidget *ViewInfo)
    {
        if (ViewInfo->objectName().isEmpty())
            ViewInfo->setObjectName(QString::fromUtf8("ViewInfo"));
        ViewInfo->resize(924, 532);
        Uname = new QLabel(ViewInfo);
        Uname->setObjectName(QString::fromUtf8("Uname"));
        Uname->setGeometry(QRect(90, 70, 291, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Console"));
        font.setPointSize(15);
        Uname->setFont(font);
        WinAndLose = new QLabel(ViewInfo);
        WinAndLose->setObjectName(QString::fromUtf8("WinAndLose"));
        WinAndLose->setGeometry(QRect(80, 210, 181, 181));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Console"));
        font1.setPointSize(14);
        WinAndLose->setFont(font1);
        JZ_1 = new QLabel(ViewInfo);
        JZ_1->setObjectName(QString::fromUtf8("JZ_1"));
        JZ_1->setGeometry(QRect(450, 70, 101, 111));
        JZ_2 = new QLabel(ViewInfo);
        JZ_2->setObjectName(QString::fromUtf8("JZ_2"));
        JZ_2->setGeometry(QRect(620, 70, 101, 111));
        Pic = new QLabel(ViewInfo);
        Pic->setObjectName(QString::fromUtf8("Pic"));
        Pic->setGeometry(QRect(620, 280, 201, 201));
        PList = new QListWidget(ViewInfo);
        PList->setObjectName(QString::fromUtf8("PList"));
        PList->setGeometry(QRect(335, 280, 231, 211));

        retranslateUi(ViewInfo);

        QMetaObject::connectSlotsByName(ViewInfo);
    } // setupUi

    void retranslateUi(QWidget *ViewInfo)
    {
        ViewInfo->setWindowTitle(QCoreApplication::translate("ViewInfo", "Form", nullptr));
        Uname->setText(QCoreApplication::translate("ViewInfo", "UserName:", nullptr));
        WinAndLose->setText(QString());
        JZ_1->setText(QString());
        JZ_2->setText(QString());
        Pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ViewInfo: public Ui_ViewInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWINFO_H
