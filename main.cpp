#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QTextStream in(stdin);
    QTextStream out(stdout);
    //QPushButton *btn = new QPushButton;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
