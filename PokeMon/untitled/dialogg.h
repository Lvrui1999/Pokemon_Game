#ifndef DIALOGG_H
#define DIALOGG_H

#include <QDialog>

namespace Ui {
class Dialogg;
}

class Dialogg : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogg(QWidget *parent = nullptr);
    ~Dialogg();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogg *ui;
};

#endif // DIALOGG_H