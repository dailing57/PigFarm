#ifndef SCENCE3_H
#define SCENCE3_H

#include <QWidget>
#include <QVector>
#include "record_info.h"
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
extern record rec;
extern record recv;
namespace Ui {
class scence3;
}

class scence3 : public QWidget
{
    Q_OBJECT

public:
    explicit scence3(QWidget *parent = nullptr);
    ~scence3();
protected:
    void closeEvent(QCloseEvent*event);
private:
    Ui::scence3 *ui;
};

#endif // SCENCE3_H
