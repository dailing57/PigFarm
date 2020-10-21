#ifndef SETTINGS_H
#define SETTINGS_H
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
#include <QMessageBox>
#include "pig_info.h"
extern int black0,black1;
namespace Ui {
class settings;
}

class settings : public QWidget
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();
    int tmp0,tmp1;
protected:
    void closeEvent(QCloseEvent*event);
private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
