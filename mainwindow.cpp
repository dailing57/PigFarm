#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,700);
    this->setWindowTitle("养猪模拟");
    this->setWindowIcon(QIcon(":/sourcefile/pig.png"));
    ui->btn->setStyleSheet("background-color: rgb(255, 255, 255)");

    scene1 *s1 = new scene1;

    connect(ui->btn,&QPushButton::clicked,[=](){
        QString user;
        QString pwd;
        user = ui->lineEdit->text();
        pwd = ui->lineEdit_2->text();
        this->hide();
        timer->start(1000);
        s1->show();

//       if(user=="NUST" && pwd == "123456")
//       {
//           this->hide();
//           s1->show();
//       }
//        else
//       {
//           QMessageBox::warning(this,"","用户名密码错误！");
//       }

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

