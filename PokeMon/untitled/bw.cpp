#include "string"
#include "bw.hpp"
#include "ui_bw.h"
#include "battle.hpp"
#include <windows.h>
#include "res.hpp"
#include "user.hpp"
extern Battle *b;
extern int result;
extern int type;
extern Poke le;
extern user u;
Poke ri;
//extern double tt;

int ha,hb,cnt,c1,c2;

BW::BW(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BW)
{
    setWindowFlags(windowFlags() &~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    std::string x = b->a.get_name();
    std::string y = b->b.get_name();
    x += ".png";
    y += ".png";
    x = "D:/XD/PokeMon/img/" + x;
    y = "D:/XD/PokeMon/img/" + y;
    const char *xx = x.c_str();
    const char *yy = y.c_str();
    ha = b->a.getheal();
    hb = b->b.getheal();
    cnt = 1;
    c1 = b->a.getint();
    c2 = b->b.getint();
    ui->P_x->setPixmap(QPixmap(xx).scaled(271,271));
    ui->P_y->setPixmap(QPixmap(yy).scaled(271,271));
    ui->Life_x->setMinimum(0);
    ui->Life_y->setMinimum(0);
    ui->Life_x->setMaximum(ha);
    ui->Life_y->setMaximum(hb);
    ui->Life_x->setValue(ha);
    ui->Life_y->setValue(hb);
    std::cout << c1 << " " << c2 << std::endl;

}

BW::~BW()
{
    delete ui;
}
void BW::on_next_clicked()
{
    if(ha <= 0 || hb <= 0){
        if(hb <= 0){
            result = 1;
            le.leveladp(15);
        }
        else result = 0;
        ri = b->b;
        u.list.push_back(le);
        std::cout << 1 << std::endl;
        res *r = new res();
        std::cout << "Fuck";
        r->show();

        this->close();
        return;
    }
    std::cout << ha << " " << hb << " "  << cnt << std::endl;
    if(cnt % c1 == 0){
        std::cout << "Aa" << std::endl;
        hb -= b->val(1,cnt/c1);
    }
    if(cnt % c2 == 0){
        std::cout << "Ab" << std::endl;
        ha -= b->val(0,cnt/c2);
    }
    ui->Life_x->setValue(ha <= 0 ? 0 : ha);
    ui->Life_y->setValue(hb <= 0 ? 0 : hb);
    cnt++;
}
