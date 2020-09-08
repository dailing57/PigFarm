#include "scene1.h"
#include "ui_scene1.h"

int curtime = 0;
QTimer * timer = new QTimer();
int coins = 10000;
Pigclass pig;

scene1::scene1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scene1)
{
    ui->setupUi(this);
    this->setFixedSize(500,700);
    this->setWindowTitle("养猪模拟");
    this->setWindowIcon(QIcon(":/sourcefile/pig.png"));

    //按钮颜色
    ui->pushButton->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_2->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_3->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_4->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_5->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_6->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_5->setStyleSheet("border-style:hiden");
    ui->pushButton_6->setStyleSheet("border-style:hiden");
    ui->pushButton_7->setStyleSheet("border-style:hiden");
    ui->pushButton_6->hide();
    ui->pushButton_8->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_9->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->label_3->setText(QString::number(coins));

    timer->stop();
    connect(timer,&QTimer::timeout,[=](){
        curtime++;
        pig.grow();
        ui->label_2->setText(QString::number(curtime)+"天");
        ui->label_3->setText(QString::number(coins));
    });
}

scene1::~scene1()
{
    delete ui;
}

void scene1::on_pushButton_clicked()
{
    //买猪
    timer->stop();
    Buy * buy1 = new Buy;
    buy1->show();
}

void scene1::on_pushButton_3_clicked()
{
    //记录
    timer->stop();
    scence3 * record1 = new scence3;
    record1->show();
}

void scene1::on_pushButton_2_clicked()
{
    //出售
    timer->stop();
    sale * sale1 = new sale;
    sale1->show();

}


//时间暂停
void scene1::on_pushButton_5_clicked()
{
    timer->stop();
    ui->pushButton_5->hide();
    ui->pushButton_6->show();
}

void scene1::on_pushButton_6_clicked()
{
    timer->start(1000);
    ui->pushButton_5->show();
    ui->pushButton_6->hide();
}

void scene1::on_pushButton_8_clicked()
{
    //查看
    watch * ptr = new watch;
    ptr->show();
}

