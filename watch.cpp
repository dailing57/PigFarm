#include "watch.h"
#include "ui_watch.h"

watch::watch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::watch)
{
    ui->setupUi(this);
    this->setFixedSize(500,400);
    this->setWindowTitle("养猪模拟");
    this->setWindowIcon(QIcon(":/sourcefile/pig.png"));

}

watch::~watch()
{
    delete ui;
}



void watch::on_lineEdit_editingFinished()
{
    ui->tableWidget->clear();
    QString s=ui->lineEdit->text();
    int safe = 0;
    if(s.isEmpty())
        QMessageBox::warning(this,"","输入不可为空！"),safe=0;
    else
    {
        int i;
        for(i=0;i<s.size();i++)
        {
            if(s[i]<'0' ||s[i] > '9')
                QMessageBox::warning(this,"","输入必须是数字！"),safe=0;
        }
        if(i==s.size())
            safe = 1;
        if(safe)
        {
            int num = ui->lineEdit->text().toInt();
            ui->tableWidget->setColumnCount(4);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"猪圈号"<<"标号"<<"体重"<<"花色");
            ui->tableWidget->setRowCount(pig.circles[num].sum_pig);
            connect(timer,&QTimer::timeout,[=](){
                Pigclass::pig * ptr= pig.circles[num].head;
                for(int i=0;i<pig.circles[num].sum_pig;i++)
                {
                    int col = 0;
                    ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number( num) ));
                    ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i)));
                    ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(ptr->weight)));
                    ui->tableWidget->setItem(i,col++,new QTableWidgetItem(ptr->color));
                    ptr=ptr->next;
                }
            });

        }
    }
}
