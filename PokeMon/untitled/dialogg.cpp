#include "dialogg.h"
#include "ui_dialogg.h"

Dialogg::Dialogg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogg)
{
    ui->setupUi(this);
}

Dialogg::~Dialogg()
{
    delete ui;
}

void Dialogg::on_pushButton_clicked()
{
    this->close();
}
