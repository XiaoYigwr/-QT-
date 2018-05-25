#include "setparameter.h"
#include <QThread>

SetParameter::SetParameter(QWidget *parent) 
{
   // ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏

}

SetParameter::~SetParameter()
{
   // delete ui;
}


void SetParameter::on_pushClean_clicked()
{
    //this->hide();
    emit open_clean();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetParameter::on_pushCheck_clicked()
{
    //this->hide();
    emit open_check();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetParameter::on_pushSetmodel_clicked()
{
    //this->hide();
    emit open_setmdole();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetParameter::on_pushProcess_clicked()
{
    //this->hide();
    emit open_process();
    emit close_self();
   // sleep(50);
    //this->hide();

}

void SetParameter::show_me(){
    //this->setWindowFlags(Qt::WindowModal);

    this->show();
    //this->setWindowState(Qt::WindowActive);
    //emit close_self();

}
