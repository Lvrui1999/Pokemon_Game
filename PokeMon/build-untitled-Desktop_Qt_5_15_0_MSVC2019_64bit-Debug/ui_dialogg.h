/********************************************************************************
** Form generated from reading UI file 'dialogg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGG_H
#define UI_DIALOGG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialogg
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialogg)
    {
        if (Dialogg->objectName().isEmpty())
            Dialogg->setObjectName(QString::fromUtf8("Dialogg"));
        Dialogg->resize(400, 300);
        label = new QLabel(Dialogg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 281, 101));
        QFont font;
        font.setFamily(QString::fromUtf8("SimSun-ExtB"));
        font.setPointSize(14);
        label->setFont(font);
        pushButton = new QPushButton(Dialogg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 230, 93, 28));

        retranslateUi(Dialogg);

        QMetaObject::connectSlotsByName(Dialogg);
    } // setupUi

    void retranslateUi(QDialog *Dialogg)
    {
        Dialogg->setWindowTitle(QCoreApplication::translate("Dialogg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialogg", "Username has been used.", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialogg", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialogg: public Ui_Dialogg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGG_H
