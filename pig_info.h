#ifndef PIGCLASS_H
#define PIGCLASS_H

#include <QString>
#include <QTextStream>
#include <QApplication>
#include <QPushButton>
#include <QMenuBar>
#include <QToolBar>
#include <QTextEdit>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QPainter>
#include <QMessageBox>
#include <QMainWindow>
#include <QTimer>

extern int curtime;
extern QTimer *timer;
extern int coins,haverec;

class Pigclass
{
public:
    Pigclass();
    class pig
    {
    public:
        QString color;
        double weight;
        int num;
        pig* next;
        pig()
        {
            weight = rand() % 30 + 21;
            next = NULL;
        }
        pig(QString c, double w)
        {
            color = c;
            weight = w;
            next = NULL;
        }
        void gorw()
        {
            double d = rand() % 12 + 1;
            this->weight += d / 10;
        }
    };

    class circle
    {
    public:
        pig* head;
        circle* next;
        int sum_pig;
        circle() { sum_pig = 0; }
    }circles[100];

    void grow();

    void change();

    void addpig(int circle_num, QString c, double w);

    void subpig(int circle_num,int pig_num);

    double pigval(QString c,double w);

    int getsum();

    pig n_circle_m_pig(int n,int m);
};

#endif // PIGCLASS_H
