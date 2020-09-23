#include <string>
#include <mainwindow.hpp>
#include "battlefiled.h"
#include "userinit.h"
#include "ui_userinit.h"
#include "user.hpp"
#include "socket.hpp"
#include <vector>
#include <string>
#include "viewinfo.h"
extern client c;
extern user u;

vector <std::string> vu;

UserInit::UserInit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInit)
{
    setWindowFlags(windowFlags() &~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    std::string s = c.get_user();
    std::string tem;
    vu.clear();
    for(auto cc : s){
        if(cc == ';'){
            vu.push_back(tem);
            ui->listWidget->addItem(QString::fromStdString(tem));
            tem.clear();
            std::cout << tem << std::endl;
        }
        else {
            tem += cc;
        }
    }
    s = c.get_all();
    for(auto cc : s){
        if(cc == ';'){
            vu.push_back(tem);
            ui->All_User->addItem(QString::fromStdString(tem));
            tem.clear();
            std::cout << tem << std::endl;
        }
        else {
            tem += cc;
        }
    }
    ui->All_User->setCurrentRow(0);
    ui->listWidget->setCurrentRow(0);

}

UserInit::~UserInit()
{
    delete ui;
}

void UserInit::on_EXit_clicked()
{
    c.save(u.get_string());
    c.Exit(u.get_name());
    this->close();
    MainWindow *w = new MainWindow();
    w->show();
}

void UserInit::on_Battle_clicked()
{
    this->close();
    BattleFiled *f = new BattleFiled();
    f->show();
}

void UserInit::on_View_Person_clicked()
{
    int now = ui->listWidget->currentRow();
    std::string uname = vu[now];
    std::string info = c.getdata(uname);
    user *view = new user();
    view->in_string(info);
    view->make_name(uname);
    ViewInfo *ff = new ViewInfo(nullptr,view);
    ff->show();
}

void UserInit::on_ReFresh_clicked()
{
    std::string s = c.get_user();
    std::string tem;
    vu.clear();
    ui->listWidget->clear();
    for(auto cc : s){
        if(cc == ';'){
            vu.push_back(tem);
            ui->listWidget->addItem(QString::fromStdString(tem));
            tem.clear();
        }
        else {
            tem += cc;
        }
    }
    ui->listWidget->setCurrentRow(0);
    ui->All_User->clear();
    s = c.get_all();
    for(auto cc : s){
        if(cc == ';'){
            vu.push_back(tem);
            ui->All_User->addItem(QString::fromStdString(tem));
            tem.clear();
        }
        else {
            tem += cc;
        }
    }
    ui->All_User->setCurrentRow(0);
}

void UserInit::on_pushButton_clicked()
{
    int now = ui->listWidget->count();
    std::string uname = vu[now + ui->All_User->currentRow()];
    std::string info = c.getdata(uname);
    user *view = new user();
    view->in_string(info);
    view->make_name(uname);
    ViewInfo *ff = new ViewInfo(nullptr,view);
    ff->show();
}
