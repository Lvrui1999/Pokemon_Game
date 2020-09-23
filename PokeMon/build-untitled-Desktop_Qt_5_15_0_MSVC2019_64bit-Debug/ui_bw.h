/********************************************************************************
** Form generated from reading UI file 'bw.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BW_H
#define UI_BW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BW
{
public:
    QLabel *P_x;
    QLabel *P_y;
    QProgressBar *Life_x;
    QProgressBar *Life_y;
    QPushButton *next;

    void setupUi(QWidget *BW)
    {
        if (BW->objectName().isEmpty())
            BW->setObjectName(QString::fromUtf8("BW"));
        BW->resize(845, 568);
        P_x = new QLabel(BW);
        P_x->setObjectName(QString::fromUtf8("P_x"));
        P_x->setGeometry(QRect(90, 130, 271, 271));
        P_y = new QLabel(BW);
        P_y->setObjectName(QString::fromUtf8("P_y"));
        P_y->setGeometry(QRect(480, 130, 271, 271));
        Life_x = new QProgressBar(BW);
        Life_x->setObjectName(QString::fromUtf8("Life_x"));
        Life_x->setGeometry(QRect(130, 40, 211, 41));
        Life_x->setValue(24);
        Life_y = new QProgressBar(BW);
        Life_y->setObjectName(QString::fromUtf8("Life_y"));
        Life_y->setGeometry(QRect(530, 40, 211, 41));
        Life_y->setValue(24);
        next = new QPushButton(BW);
        next->setObjectName(QString::fromUtf8("next"));
        next->setGeometry(QRect(240, 480, 93, 28));

        retranslateUi(BW);

        QMetaObject::connectSlotsByName(BW);
    } // setupUi

    void retranslateUi(QWidget *BW)
    {
        BW->setWindowTitle(QCoreApplication::translate("BW", "Form", nullptr));
        P_x->setText(QString());
        P_y->setText(QString());
        next->setText(QCoreApplication::translate("BW", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BW: public Ui_BW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BW_H
