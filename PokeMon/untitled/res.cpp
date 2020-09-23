#include "res.hpp"
#include "ui_res.h"
#include "poke.hpp"
#include <vector>
#include <iostream>
#include "user.hpp"
#include <random>
#include <time.h>
#include <algorithm>
#include "battlefiled.h"
#include <QPixmap>
#include <string>
#include "socket.hpp"
#include "userinit.h"
int result;
extern user u;
extern Poke le;
extern Poke ri;
extern int type;
extern client c;
vector <Poke> ve;
res::res(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::res)
{
    setWindowFlags(windowFlags() &~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    if(result == 0)u.al();
    else u.aw();
    if(result == 0 && type == 2){
        ui->ResText->setText(QString::fromStdString("Defeat"));
        ui->Pic->hide();
//        random_shuffle(u.list.begin(),u.list.end());
        for(int i = 0; i < (u.list.size() < 3 ? u.list.size() : 3); i++){
            ve.push_back(u.list[i]);
        }
        for(auto p : ve)
            ui->ChoseList->addItem(QString::fromStdString(p.get_name()));
//        ui->Pic
        ui->ChoseList->setCurrentRow(0);
    }
    else{
        if(result == 1)
            ui->ResText->setText(QString::fromStdString("Victory"));
        else
            ui->ResText->setText(QString::fromStdString("Defeat"));
        if(type == 2){
            u.list.push_back(ri);
        }
        ui->ChoseList->hide();
//        ui->View->hide();
        std::string x = le.get_name();
        x += ".png";
        x = "D:/XD/PokeMon/img/" + x;
        ui->Pic->setPixmap(QPixmap(QString::fromStdString(x)).scaled(301,301));
        ui->Shower->clear();
        std::string usings = "name:" + le.get_name() + "\natk:" + le.trans(le.getatk()) + "\ndef:" + le.trans(le.getdef()) + "\nheal:" + le.trans(le.getheal()) + "\n";
        ui->Shower->insertPlainText(QString::fromStdString(usings));
    }

}

res::~res()
{
    delete ui;
}

void res::on_Confirm_clicked()
{
    if(result == 0 && type == 2){
        int now = ui->ChoseList->currentRow();
        vector <Poke> fuck;
        for(int i = 0; i < u.list.size(); i++){
            if(i != now){
                fuck.push_back(u.list[i]);
            }
        }
        u.list = fuck;
        if(u.list.size() == 0){
            u.init(1);
        }

    }
    c.save(u.get_string());
    this->close();
    UserInit *b = new UserInit();
    b->show();

}

void res::on_ChoseList_currentTextChanged(const QString &currentText)
{
    int now = ui->ChoseList->currentRow();
    if(now == -1)return;
    Poke sl = ve[now];
//    Poke sl = v[now];
    std::string x = sl.get_name();
    x += ".png";
    x = "D:/XD/PokeMon/img/" + x;
    const char *xxx = x.c_str();
    ui->Pic_y->setPixmap(QPixmap(xxx).scaled(231,231));
    ui->Shower->clear();
    std::string output;
    output += "name:" + sl.get_name() + "\n" + "atk:" + sl.trans(sl.getatk()) + "\n" + "def:" + sl.trans(sl.getdef()) + "\n" + "heal:" + sl.trans(sl.getheal()) + "\n" + "attackinterval:" + sl.trans(sl.getint()) + "\n";
    ui->Shower->insertPlainText(QString::fromStdString(output));
}
