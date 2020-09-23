#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "user.hpp"
#include "dialog.h"
#include "socket.hpp"
#include "battlefiled.h"
#include "userinit.h"
#include "dialogg.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



extern client c;
extern user u;



void MainWindow::on_Login_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    string uname = username.toStdString();
    string pword = password.toStdString();
    if(c.login(uname,pword)){
        u.in_string(c.getdata(uname));
        u.make_name(uname);
        UserInit *f = new UserInit();
        std::cout << "?" << endl;
        f->show();

        this->close();
        return;
    }
    else{
        Dialog A;
        A.exec();
        ui->Username->clear();
        ui->Password->clear();
        return;
    }
}

void MainWindow::on_Register_clicked()
{
    QString username = ui->Username->text();
    QString password = ui->Password->text();
    string uname = username.toStdString();
    string pword = password.toStdString();
    if(c.regist(uname,pword)){
        u.init(3);
        u.make_name(uname);
        c.save(u.get_string());
    }
    else{
        Dialogg A;
        A.exec();
        ui->Username->clear();
        ui->Password->clear();
        return;
    }
}
