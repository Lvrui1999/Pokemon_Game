#ifndef VIEWINFO_H
#define VIEWINFO_H

#include <QWidget>
#include "user.hpp"
namespace Ui {
class ViewInfo;
}

class ViewInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ViewInfo(QWidget *parent = nullptr, user *u = nullptr);
    ~ViewInfo();

private slots:
    void on_PList_currentTextChanged(const QString &currentText);

private:
    Ui::ViewInfo *ui;
};

#endif // VIEWINFO_H
