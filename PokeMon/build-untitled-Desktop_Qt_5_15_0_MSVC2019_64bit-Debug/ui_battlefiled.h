/********************************************************************************
** Form generated from reading UI file 'battlefiled.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEFILED_H
#define UI_BATTLEFILED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BattleFiled
{
public:
    QPushButton *BattleType1;
    QPushButton *BattleType2;
    QPushButton *Save;
    QListWidget *PokeList;
    QPushButton *Battle1;
    QPushButton *Back;
    QLabel *Pic;
    QLabel *Title;
    QLabel *Shower;

    void setupUi(QWidget *BattleFiled)
    {
        if (BattleFiled->objectName().isEmpty())
            BattleFiled->setObjectName(QString::fromUtf8("BattleFiled"));
        BattleFiled->resize(877, 674);
        BattleType1 = new QPushButton(BattleFiled);
        BattleType1->setObjectName(QString::fromUtf8("BattleType1"));
        BattleType1->setGeometry(QRect(100, 610, 93, 28));
        BattleType2 = new QPushButton(BattleFiled);
        BattleType2->setObjectName(QString::fromUtf8("BattleType2"));
        BattleType2->setGeometry(QRect(380, 610, 93, 28));
        Save = new QPushButton(BattleFiled);
        Save->setObjectName(QString::fromUtf8("Save"));
        Save->setGeometry(QRect(660, 610, 93, 28));
        PokeList = new QListWidget(BattleFiled);
        PokeList->setObjectName(QString::fromUtf8("PokeList"));
        PokeList->setGeometry(QRect(80, 190, 256, 351));
        QFont font;
        font.setPointSize(14);
        PokeList->setFont(font);
        Battle1 = new QPushButton(BattleFiled);
        Battle1->setObjectName(QString::fromUtf8("Battle1"));
        Battle1->setGeometry(QRect(240, 610, 93, 28));
        Back = new QPushButton(BattleFiled);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(520, 610, 93, 28));
        Pic = new QLabel(BattleFiled);
        Pic->setObjectName(QString::fromUtf8("Pic"));
        Pic->setGeometry(QRect(520, 130, 241, 231));
        Title = new QLabel(BattleFiled);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(250, 30, 351, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Arabic"));
        font1.setPointSize(28);
        Title->setFont(font1);
        Shower = new QLabel(BattleFiled);
        Shower->setObjectName(QString::fromUtf8("Shower"));
        Shower->setGeometry(QRect(490, 400, 291, 181));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(14);
        Shower->setFont(font2);

        retranslateUi(BattleFiled);

        QMetaObject::connectSlotsByName(BattleFiled);
    } // setupUi

    void retranslateUi(QWidget *BattleFiled)
    {
        BattleFiled->setWindowTitle(QCoreApplication::translate("BattleFiled", "Form", nullptr));
        BattleType1->setText(QCoreApplication::translate("BattleFiled", "Choose", nullptr));
        BattleType2->setText(QCoreApplication::translate("BattleFiled", "Duel", nullptr));
        Save->setText(QCoreApplication::translate("BattleFiled", "Save&Exit", nullptr));
        Battle1->setText(QCoreApplication::translate("BattleFiled", "LevelUp", nullptr));
        Back->setText(QCoreApplication::translate("BattleFiled", "Back", nullptr));
        Pic->setText(QString());
        Title->setText(QCoreApplication::translate("BattleFiled", "Choose Enemy", nullptr));
        Shower->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BattleFiled: public Ui_BattleFiled {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEFILED_H
