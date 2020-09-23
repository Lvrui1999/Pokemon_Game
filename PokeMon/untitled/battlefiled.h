#ifndef BATTLEFILED_H
#define BATTLEFILED_H

#include <QWidget>

namespace Ui {
class BattleFiled;
}

class BattleFiled : public QWidget
{
    Q_OBJECT

public:
    explicit BattleFiled(QWidget *parent = nullptr);
    ~BattleFiled();

private slots:
    void on_Save_clicked();

    void on_BattleType1_clicked();

    void on_Back_clicked();

    void on_Battle1_clicked();

    void on_BattleType2_clicked();

    void on_PokeList_currentTextChanged(const QString &currentText);

private:
    Ui::BattleFiled *ui;
};

#endif // BATTLEFILED_H
