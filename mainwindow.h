#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scene1.h"
#include "scence3.h"
#include "pig_info.h"
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
