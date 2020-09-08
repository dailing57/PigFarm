#include "buy.h"
#include "ui_buy.h"



Buy::Buy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Buy)
{
    ui->setupUi(this);
    this->setFixedSize(401,491);
    this->setWindowTitle("养猪模拟");
    this->setWindowIcon(QIcon(":/sourcefile/pig.png"));
    singleval=-1;
    weight=0;
    cost=-1;
    realbuy=-1;
    num=-1;
    colorstate=-1;
    date=-1;

}

Buy::~Buy()
{
    delete ui;
    //qDebug()<<"abc"<<endl;
}

void Buy::on_radioButton_clicked()
{
    colorstate = 1;
    singleval = 15;
    ui->label_7->setText("15");
    cost = weight*singleval;
    QString res=QString::number(cost);
    ui->label_9->setText(res);
}

void Buy::on_radioButton_2_clicked()
{
    colorstate = 2;
    singleval = 6;
    ui->label_7->setText("6");
    cost = weight*singleval;
    QString res=QString::number(cost);
    ui->label_9->setText(res);
}

void Buy::on_radioButton_3_clicked()
{
    colorstate = 3;
    singleval = 7;
    ui->label_7->setText("7");
    cost = weight*singleval;
    QString res=QString::number(cost);
    ui->label_9->setText(res);
}

void Buy::on_lineEdit_editingFinished()
{
     weight = ui->lineEdit->text().toDouble();
     if(weight<20 || weight>50)
     {
         QMessageBox::warning(this,"","猪崽的重量为20~50kg");
     }
     else
     {
         cost = weight*singleval;
         QString res=QString::number(cost);
         ui->label_9->setText(res);
     }
}

void Buy::on_lineEdit_2_editingFinished()
{
    num = ui->lineEdit_2->text().toInt();
    if(num>=100 && num<0)
    {
        QMessageBox::warning(this,"","不在猪圈范围内！");
    }
}

void Buy::on_pushButton_clicked()
{
    QString scolor;

    if(colorstate==1)
        scolor = "黑";
    else if(colorstate == 2)
        scolor = "白";
    else
        scolor = "花";

   if(weight == 0 || colorstate == -1 || num == -1 )
       QMessageBox::warning(this,"","猪的信息不可以为空！");
   else if(colorstate == 1 && num < 90)
       QMessageBox::warning(this,"","为了和平，黑猪只可以再90~100号猪圈！");
   else if(pig.circles[num].sum_pig==10)
       QMessageBox::warning(this,"","一个猪圈最多10只猪");
   else
   {
       pig.addpig(num,scolor,weight);
       rec.addrecord(rec.currecord,num,pig.circles[num].sum_pig,weight,scolor,"购买",curtime);
       timer->start(1000);
       coins -= cost;
       this->close();
       //delete (this);
   }

}

void Buy::closeEvent(QCloseEvent *event)
{
    timer->start(1000);
    this->close();
    //delete(this);
}

