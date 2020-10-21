#include "settings.h"
#include "ui_settings.h"
int black0=90,black1=100;
settings::settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_lineEdit_editingFinished()
{
    tmp0=ui->lineEdit->text().toInt();
}

void settings::on_lineEdit_2_editingFinished()
{
    tmp1=ui->lineEdit_2->text().toInt();
}

void settings::on_pushButton_clicked()
{
    if(tmp0>=0 && tmp1<=100 && tmp0<tmp1)
    {
        black0=tmp0;
        black1=tmp1;
        this->close();
        timer->start(1000);
    }
    else
    {
        QMessageBox::warning(this,"","输入有错误");
    }
}

void settings::closeEvent(QCloseEvent *event)
{
    timer->start(1000);
    this->close();
    //delete(this);
}
