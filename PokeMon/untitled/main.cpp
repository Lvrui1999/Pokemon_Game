#include "mainwindow.hpp"
#include "user.hpp"
#include "socket.hpp"
#include <QApplication>

client c;
user u;
int main(int argc, char *argv[])
{
    c.init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
