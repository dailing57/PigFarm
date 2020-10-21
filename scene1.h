#ifndef SCENE1_H
#define SCENE1_H

#include "ui_scene1.h"
#include "pig_info.h"
#include "buy.h"
#include "scence3.h"
#include "record_info.h"
#include "sale.h"
#include "watch.h"
#include "virus.h"
#include "settings.h"
#include "help.h"

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
#include <QWidget>
#include <QTimer>
#include <QFile>
#include <QDataStream>

namespace Ui {
class scene1;
}



class scene1 : public QWidget
{
    Q_OBJECT

public:
    explicit scene1(QWidget *parent = nullptr);
    ~scene1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::scene1 *ui;
};

#endif // SCENE1_H
