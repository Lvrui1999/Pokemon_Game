#ifndef USERINIT_H
#define USERINIT_H

#include <QWidget>

namespace Ui {
class UserInit;
}

class UserInit : public QWidget
{
    Q_OBJECT

public:
    explicit UserInit(QWidget *parent = nullptr);
    ~UserInit();

private slots:
    void on_EXit_clicked();

    void on_Battle_clicked();

    void on_View_Person_clicked();

    void on_ReFresh_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserInit *ui;
};

#endif // USERINIT_H
