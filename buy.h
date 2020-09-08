#ifndef BUY_H
#define BUY_H

#include <QWidget>
#include "pig_info.h"
#include "scence3.h"
#include "record_info.h"

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

extern Pigclass pig;

namespace Ui {
class Buy;
}

class Buy : public QWidget
{
    Q_OBJECT

public:
    explicit Buy(QWidget *parent = nullptr);
    ~Buy();
    double singleval,weight,cost;
    int realbuy,num,colorstate,date;
protected:
    void closeEvent(QCloseEvent*event);
private slots:
    void on_radioButton_clicked();

    void on_lineEdit_editingFinished();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_2_editingFinished();

private:
    Ui::Buy *ui;
};

#endif // BUY_H
