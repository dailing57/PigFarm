#ifndef RECORD_H
#define RECORD_H
#include <QList>
#include "pig_info.h"
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

class record
{
public:
    record();
    int currecord;
    QList<int> recordnum,circlenum,pignum,date;
    QList<double> weight;
    QList<QString> color,state;
    void addrecord(int recordnum,int circlenum,int pignum,double weight,QString color,QString state,int date);
};

#endif // RECORD_H
