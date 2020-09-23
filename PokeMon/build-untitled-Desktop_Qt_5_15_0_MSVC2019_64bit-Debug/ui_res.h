/********************************************************************************
** Form generated from reading UI file 'res.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RES_H
#define UI_RES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_res
{
public:
    QLabel *ResText;
    QListWidget *ChoseList;
    QTextBrowser *Shower;
    QPushButton *Confirm;
    QLabel *Pic;
    QLabel *Pic_y;

    void setupUi(QWidget *res)
    {
        if (res->objectName().isEmpty())
            res->setObjectName(QString::fromUtf8("res"));
        res->resize(1099, 727);
        ResText = new QLabel(res);
        ResText->setObjectName(QString::fromUtf8("ResText"));
        ResText->setGeometry(QRect(480, 70, 181, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Arabic"));
        font.setPointSize(48);
        ResText->setFont(font);
        ChoseList = new QListWidget(res);
        ChoseList->setObjectName(QString::fromUtf8("ChoseList"));
        ChoseList->setGeometry(QRect(180, 230, 256, 321));
        QFont font1;
        font1.setPointSize(11);
        ChoseList->setFont(font1);
        Shower = new QTextBrowser(res);
        Shower->setObjectName(QString::fromUtf8("Shower"));
        Shower->setGeometry(QRect(660, 450, 291, 111));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        Shower->setFont(font2);
        Confirm = new QPushButton(res);
        Confirm->setObjectName(QString::fromUtf8("Confirm"));
        Confirm->setGeometry(QRect(520, 610, 93, 28));
        Pic = new QLabel(res);
        Pic->setObjectName(QString::fromUtf8("Pic"));
        Pic->setGeometry(QRect(140, 240, 301, 301));
        Pic_y = new QLabel(res);
        Pic_y->setObjectName(QString::fromUtf8("Pic_y"));
        Pic_y->setGeometry(QRect(690, 210, 231, 231));

        retranslateUi(res);

        QMetaObject::connectSlotsByName(res);
    } // setupUi

    void retranslateUi(QWidget *res)
    {
        res->setWindowTitle(QCoreApplication::translate("res", "Form", nullptr));
        ResText->setText(QCoreApplication::translate("res", "Success", nullptr));
        Confirm->setText(QCoreApplication::translate("res", "Confirm", nullptr));
        Pic->setText(QCoreApplication::translate("res", "TextLabel", nullptr));
        Pic_y->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class res: public Ui_res {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RES_H
