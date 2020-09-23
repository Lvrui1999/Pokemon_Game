#include "viewinfo.h"
#include "ui_viewinfo.h"
#include "user.hpp"

ViewInfo::ViewInfo(QWidget *parent,user *u) :
    QWidget(parent),
    ui(new Ui::ViewInfo)
{
    ui->setupUi(this);
    ui->Uname->setText(QString::fromStdString("Username:" + u->get_name()));
    ui->WinAndLose->setText(QString::fromStdString("Win/Lose:" + u->trans(u->win) + "/" + u->trans(u->lose)));
    int cnt1 = 0;
    int cnt2 = 0;
    for(auto p : u->list){
        ui->PList->addItem(QString::fromStdString(p.get_name()));
        cnt1++;
        if(p.gle() == 15){
            cnt2++;
        }
    }
    if(cnt1 >= 1 && cnt1 < 50){
        ui->JZ_1->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/JZ_1_1.png")).scaled(101,111));
    }
    else if(cnt1 >= 50 && cnt1 < 80){
        ui->JZ_1->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/JZ_1_2.png")).scaled(101,111));
    }
    else if(cnt1 >= 80){
        ui->JZ_1->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/JZ_1_3.png")).scaled(101,111));
    }
    if(cnt2 >= 1 && cnt2 < 25){
        ui->JZ_2->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/JZ_2_1.png")).scaled(101,111));
    }
    else if(cnt2 >= 25 && cnt2 < 40){
        ui->JZ_2->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/JZ_2_2.png")).scaled(101,111));
    }
    else if(cnt2 >= 40){
        ui->JZ_2->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/JZ_2_3.png")).scaled(101,111));
    }
}

ViewInfo::~ViewInfo()
{
    delete ui;
}

void ViewInfo::on_PList_currentTextChanged(const QString &currentText)
{
    ui->Pic->setPixmap(QPixmap(QString::fromStdString("D:/XD/PokeMon/img/" + currentText.toStdString() + ".png")).scaled(201,201));
}
