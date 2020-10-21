#include "scene1.h"
#include "ui_scene1.h"

int curtime = 0;
QTimer * timer = new QTimer();
int coins = 10000;
Pigclass pig;
int haverec = 0;

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
    ui->pushButton_10->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_11->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_12->setStyleSheet("background-color: rgb(154, 166, 154)");
    ui->pushButton_13->setStyleSheet("background-color: rgb(154, 166, 154)");
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
        //ui->label_3->setText(QString::number(coins));
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
    connect(buy1,&Buy::bought,this,[=](){
        ui->label_3->setText(QString::number(coins));
    });
}

void scene1::on_pushButton_3_clicked()
{
    //记录
    if(!haverec)
        QMessageBox::warning(this,"","还没有任何记录");
    else
    {
        timer->stop();
        scence3 * record1 = new scence3;
        record1->show();
    }
}

void scene1::on_pushButton_2_clicked()
{
    //出售
    timer->stop();
    sale * sale1 = new sale;
    sale1->show();
    connect(sale1,&sale::sold,[=](){
        ui->label_3->setText(QString::number(coins));
    });
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


void scene1::on_pushButton_9_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("提示");
    msgBox.setWindowIcon(QIcon(":/sourcefile/pig.png"));
    msgBox.setInformativeText("确定开始病毒模拟?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Yes){
        virus *ptr = new virus;
        ptr->show();
    }
}

void scene1::on_pushButton_13_clicked()
{
    QFile::remove("file.dat");
    QFile aFile("file.dat");
    aFile.open(QIODevice::WriteOnly);//用只写的方式打开文件
    QDataStream aStream(&aFile);
    aStream << curtime;
    aStream << coins;
    aStream << infect;
    aStream << sa;
    aStream << rec.currecord;
    qDebug()<<curtime<<" "<<coins<<" "<<infect<<" "<<sa<<" "<<rec.currecord<<endl;
    for(int i=0;i<rec.currecord;i++)
    {
        aStream<<rec.recordnum[i]<<rec.circlenum[i]<<rec.pignum[i]<<rec.date[i]<<rec.weight[i]<<rec.color[i]<<rec.state[i];
    }
    aStream<<recv.currecord0;
    for(int i=0;i<recv.currecord0;i++)
    {
        aStream<<rec.recordnum[i]<<rec.circlenum[i]<<rec.pignum[i]<<rec.date[i]<<rec.weight[i]<<rec.color[i]<<rec.state[i];
    }

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<10;j++)
        {
            aStream << vis[i][j];
        }
    }
    for(int i=0;i<100;i++)
    {
        aStream << vis0[i];
    }
    for(int i=0;i<100;i++)
    {
        Pigclass::pig *ptr = pig.circles[i].head;
        aStream<<pig.circles[i].sum_pig;
        while(ptr!=NULL)
        {
            aStream<<ptr->num<<ptr->color<<ptr->weight;
            ptr=ptr->next;
        }
    }
}

void scene1::on_pushButton_4_clicked()
{
    QMessageBox::warning(this,"","经过隔离治疗，猪已经全部恢复！");
    memset(vis,0,sizeof(vis));
    memset(vis0,0,sizeof(vis0));

}

void scene1::on_pushButton_12_clicked()
{
    QFile aFile("file.dat");
    aFile.open(QIODevice::ReadOnly);//用只读的方式打开文件
    QDataStream aStream(&aFile);
    aStream >> curtime;
    aStream >> coins;
    aStream >> infect;
    aStream >> sa;
    rec.clear();
    int records;
    aStream >> records;
    qDebug()<<curtime<<" "<<coins<<" "<<infect<<" "<<sa<<" "<<rec.currecord<<endl;
    for(int i=0;i<records;i++)
    {
        //qDebug()<<rec.currecord<<endl;
        int recordnum, circlenum, pignum,date;
        double weight;
        QString color, state;
        aStream>>recordnum>>circlenum>>pignum>>date>>weight>>color>>state;
        rec.addrecord(recordnum,circlenum,pignum,weight,color,state,date);
    }
    recv.clear();
    aStream>>records;
    for(int i=0;i<records;i++)
    {
        int recordnum, circlenum, pignum,date;
        double weight;
        QString color, state;
        aStream>>recordnum>>circlenum>>pignum>>date>>weight>>color>>state;
        recv.addrecordv(recordnum,circlenum,pignum,weight,color,state,date);
    }

    for(int i=0;i<100;i++)
    {
        for(int j=0;j<10;j++)
        {
            aStream >> vis[i][j];
        }
    }
    for(int i=0;i<100;i++)
    {
        aStream >> vis0[i];
    }
    for(int i=0;i<100;i++)
    {
        Pigclass::pig *ptr = new Pigclass::pig;
        aStream>>pig.circles[i].sum_pig;
        if(pig.circles[i].sum_pig==0)
            pig.circles[i].head=NULL;
        else
        {
            pig.circles[i].head=ptr;
            for(int j=0;j<pig.circles[i].sum_pig;j++)
            {
                aStream>>ptr->num>>ptr->color>>ptr->weight;
                Pigclass::pig *nxt = new Pigclass::pig;
                if(j==pig.circles[i].sum_pig)
                    ptr->next=NULL;
                else
                {
                    ptr->next=nxt;
                    ptr=ptr->next;
                }
            }
        }
    }
}

void scene1::on_pushButton_11_clicked()
{
    timer->stop();
    settings * sets = new settings;
    sets->show();
}

void scene1::on_pushButton_10_clicked()
{
    help *h=new help;
    h->show();
}
