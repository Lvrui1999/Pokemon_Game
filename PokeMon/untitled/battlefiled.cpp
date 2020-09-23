#include "battlefiled.h"
#include "ui_battlefiled.h"
#include "socket.hpp"
#include "user.hpp"
#include "mainwindow.hpp"
#include "pokemondict.hpp"
#include "pokemon.hpp"
#include "poke.hpp"
#include <time.h>
#include <vector>
#include "battle.hpp"
#include "bw.hpp"
#include "userinit.h"
extern user u;
extern client c;
Poke yy;
bool choose = 0;
vector <Poke> v;
vector <Poke> vv;
Poke le;
int type = 0;
extern int result;
Battle *b;

//extern MainWindow w;
BattleFiled::BattleFiled(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleFiled)
{
    setWindowFlags(windowFlags() &~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    ui->Battle1->hide();
    ui->BattleType2->hide();
    ui->Back->hide();
    Dict pd = Dict();
    v.clear();
    std::string ss = "D:/XD/Pokemon_Game/data/Pokemon.txt";
    pd.init(ss);
    int size = pd.v.size();
    srand(time(NULL));
    for(int i = 1; i <= 10; i++){
        Pokemon now = pd.v[rand()%size];
        Poke nnow = now.getone();
        int le = i - 1;
        for(int j = 1; j <= le; j++){
            nnow.update();
        }
        v.push_back(nnow);
    }
    for(auto p : v){
        ui->PokeList->addItem(QString::fromStdString(p.get_name()));
    }
    ui->PokeList->setCurrentRow(0);
}

BattleFiled::~BattleFiled()
{
    delete ui;
}
void BattleFiled::on_Save_clicked()
{
    c.save(u.get_string());
    this->hide();
    UserInit *w = new UserInit();
    w->show();

}

void BattleFiled::on_BattleType1_clicked()
{
    ui->BattleType1->hide();
    ui->Battle1->show();
    ui->Back->show();
    ui->Title->setText(QString::fromStdString("Choose Your Pokemon"));
    int now = ui->PokeList->currentRow();
    std::cout << now << std::endl;
    yy = v[now];
    ui->BattleType2->show();
    ui->Save->hide();
    ui->PokeList->clear();
    ui->Pic->clear();
    vv = v;
    v.clear();
    ui->Shower->clear();
    for(auto p : u.list)
        v.push_back(p);
    for(auto p : v)
        ui->PokeList->addItem(QString::fromStdString(p.get_name()));
    ui->PokeList->setCurrentRow(0);
}

void BattleFiled::on_Back_clicked()
{
    ui->BattleType1->show();
    ui->Battle1->hide();
    ui->BattleType2->hide();
    ui->Back->hide();
    ui->Save->show();
    ui->PokeList->clear();
    ui->Shower->clear();
    ui->Pic->clear();
    v.clear();
    v = vv;
    for(auto p : v)
        ui->PokeList->addItem(QString::fromStdString(p.get_name()));
}
void BattleFiled::on_Battle1_clicked()
{
    Poke xx = v[ui->PokeList->currentRow()];
    vector <Poke> ve;
    for(int i = 0; i < u.list.size(); i++){
        if(i != ui->PokeList->currentRow()){
            ve.push_back(u.list[i]);
        }
    }
    u.list = ve;
    le = xx;
    b = new Battle(xx,yy);
    BW *bb = new BW();
    bb->show();
    type = 1;
    this->close();
//    bb->run();
    //Battle qian duan
}
void BattleFiled::on_BattleType2_clicked()
{
    Poke xx = v[ui->PokeList->currentRow()];
    vector <Poke> ve;
    for(int i = 0; i < u.list.size(); i++){
        if(i != ui->PokeList->currentRow()){
            ve.push_back(u.list[i]);
        }
    }
    u.list = ve;
    le = xx;
    b = new Battle(xx,yy);
    BW *bb = new BW();
    bb->show();
    type = 2;
    this->close();
}

void BattleFiled::on_PokeList_currentTextChanged(const QString &currentText)
{
    int now = ui->PokeList->currentRow();
    if(now == -1)return;
    std::cout << now << std::endl;
    Poke sl = v[now];
    std::string x = sl.get_name();
    x += ".png";
    x = "D:/XD/PokeMon/img/" + x;
    const char *xxx = x.c_str();
    ui->Pic->setPixmap(QPixmap(xxx).scaled(231,231));
    ui->Shower->clear();
    string output;
    output += "name:" + sl.get_name() + "\n" + "atk:" + sl.trans(sl.getatk()) + "\n" + "def:" + sl.trans(sl.getdef()) + "\n" + "heal:" + sl.trans(sl.getheal()) + "\n" + "attackinterval:" + sl.trans(sl.getint()) + "\n";
    ui->Shower->setText(QString::fromStdString(output));
}
