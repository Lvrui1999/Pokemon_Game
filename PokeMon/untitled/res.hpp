#ifndef RES_HPP
#define RES_HPP

#include <QWidget>

namespace Ui {
class res;
}

class res : public QWidget
{
    Q_OBJECT

public:
    explicit res(QWidget *parent = nullptr);
    ~res();

private slots:
    void on_Confirm_clicked();

    void on_ChoseList_currentTextChanged(const QString &currentText);

private:
    Ui::res *ui;
};

#endif // RES_HPP
