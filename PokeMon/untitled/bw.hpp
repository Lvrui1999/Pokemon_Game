#ifndef BW_HPP
#define BW_HPP

#include <QWidget>

namespace Ui {
class BW;
}

class BW : public QWidget
{
    Q_OBJECT

public:
    explicit BW(QWidget *parent = nullptr);
    ~BW();

private slots:
    void on_next_clicked();

private:
    Ui::BW *ui;
};

#endif // BW_HPP
