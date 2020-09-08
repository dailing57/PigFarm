#include "scence3.h"
#include "ui_scence3.h"

record rec;

scence3::scence3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scence3)
{
    ui->setupUi(this);
    this->setWindowTitle("养猪模拟");
    this->setWindowIcon(QIcon(":/sourcefile/pig.png"));

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"流水号"<<"猪圈号"<<"标号"<<"体重"<<"花色"<<"动态"<<"日期");

    ui->tableWidget->setRowCount(rec.currecord);
    //qDebug()<<rec.currecord<<" "<<rec.circlenum[0]<<" "<<rec.pignum[0]<<" "<<rec.weight[0]<<" "<<rec.color[0]<<" "<<rec.state[0]<<" "<<1;
    for(int i=0;i<rec.currecord;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number( rec.recordnum[i]) ));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(rec.circlenum[i])));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(rec.pignum[i])));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(rec.weight[i])));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(rec.color[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(rec.state[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(rec.date[i])));
    }
}

void scence3::closeEvent(QCloseEvent *event)
{
    timer->start(1000);
    this->close();
}

scence3::~scence3()
{
    delete ui;
}
