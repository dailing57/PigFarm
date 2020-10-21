#include "virus.h"
#include "ui_virus.h"
#include <QTime>
record recv;
bool vis[100][10],vis0[100];
Pigclass:: pig tmp;
int infect;
bool sa = 0;

virus::virus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::virus)
{
    ui->setupUi(this);
    this->setWindowTitle("养猪模拟");
    this->setWindowIcon(QIcon(":/sourcefile/pig.png"));

    memset(vis,0,sizeof(vis));
    memset(vis0,0,sizeof(vis0));

    int cnum=0,pignum=0;
    int a[100];
    int cnt = 0;

    for(int i=0;i<100;i++)
    {
        if(pig.circles[i].sum_pig)
            a[cnt++] = i;
    }

    if(cnt!=0)
    {
        cnum = a[qrand()%cnt];
        vis0[cnum]=1;
        pignum = qrand()%pig.circles[cnum].sum_pig;
        vis[cnum][pignum]=1;
        tmp=pig.n_circle_m_pig(cnum,pignum);
        recv.addrecordv(recv.currecord0,cnum,tmp.num,tmp.weight,tmp.color,"感染",curtime);
        int begintime=curtime;
        int sumpig = pig.getsum();

        connect(timer,&QTimer::timeout,[=](){

            //ui->tableWidget->show();

            infect = 0;
            for(int i=0;i<100;i++)
            {
                if(vis0[i]==1)
                {
                    for(int j=0;j<pig.circles[i].sum_pig;j++)
                    {
                        if(vis[i][j]==0)
                        {
                           qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+j*4);
                           if(qrand()%2)
                           {
                               vis[i][j]=1;
                               tmp = pig.n_circle_m_pig(i,j);
                               //pig.subpig(i,j);
                               recv.addrecordv(recv.currecord0,i,tmp.num,tmp.weight,tmp.color,"感染",curtime);
                           }
                        }
                    }
                }
                if(i!=0 && vis0[i-1]==0)
                {
                    for(int j=0;j<pig.circles[i-1].sum_pig;j++)
                    {
                        if(vis[i-1][j]==0)
                        {
                           qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+j*2);
                           if(qrand()%100<15)
                           {
                               vis[i-1][j]=1,vis0[i-1]=1;
                               tmp = pig.n_circle_m_pig(i-1,j);
                               //pig.subpig(i-1,j);
                               recv.addrecordv(recv.currecord0,i-1,tmp.num,tmp.weight,tmp.color,"感染",curtime);
                           }
                        }
                    }
                }
                if(i!=99 && vis0[i+1]==0)
                {
                    for(int j=0;j<pig.circles[i+1].sum_pig;j++)
                    {
                        if(vis[i+1][j]==0)
                        {
                           qsrand(QTime(0,0,0).secsTo(QTime::currentTime())+3*j);
                           if(qrand()%100<15)
                           {
                               vis[i+1][j]=1,vis0[i+1]=1;
                               tmp = pig.n_circle_m_pig(i+1,j);
                               //pig.subpig(i+1,j);
                               recv.addrecordv(recv.currecord0,i+1,tmp.num,tmp.weight,tmp.color,"感染",curtime);
                           }
                        }
                    }
                }
            }

            for(int i=0;i<100;i++)
            {
                for(int j=0;j<10;j++)
                {
                    if(vis[i][j])
                        infect++;
                }
            }

            ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(7);
            ui->tableWidget->setRowCount(recv.currecord0);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"感染号"<<"猪圈号"<<"标号"<<"体重"<<"花色"<<"状态"<<"日期");
            for(int i=0;i<recv.currecord0;i++)
            {
                int col = 0;
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number( recv.recordnum[i]) ));
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(recv.circlenum[i])));
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(recv.pignum[i])));
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(recv.weight[i])));
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(recv.color[i]));
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(recv.infected[i]));
                ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(recv.date[i])));
            }

            //ui->label_2->setText("经过"+QString::number(curtime - begintime)+"天,感染了"+QString::number(infect)+"头猪");

            if(infect == sumpig)
            {
                timer->stop();
                QMessageBox msgBox;
                if(!sa)
                {
                    msgBox.setText("提示");
                    msgBox.setWindowIcon(QIcon(":/sourcefile/pig.png"));
                    msgBox.setInformativeText("已经全部感染！");
                    msgBox.setStandardButtons(QMessageBox::Ok);
                    msgBox.setDefaultButton(QMessageBox::Ok);
                    int ret = msgBox.exec();
                    if(ret == QMessageBox::Ok){
                        this->close();
                        sa =1;
                        timer->start(1000);
                    }
                }
                if(sa)
                    timer->start(1000);
            }

        });
    }
    else
        this->close();
}


virus::~virus()
{
    delete ui;
}
