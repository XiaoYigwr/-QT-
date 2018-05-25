#include "clean.h"
#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include <QLinearGradient>



Clean::Clean(QWidget *parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

Clean::~Clean()
{
   // delete ui;
}

void Clean::on_pushSetp_clicked()
{
    //this->hide();
    emit open_setparameter();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Clean::on_pushCheck_clicked()
{
    //this->hide();
    emit open_check();
    emit close_self();
    //sleep(50);
    //this->hide();


}

void Clean::on_pushSetm_clicked()
{
    //this->hide();
    emit open_setmdole();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Clean::on_pushProcess_clicked()
{
    //this->hide();
    emit open_process();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Clean::show_me(){
    //this->setWindowFlags(Qt::WindowModal);

    this->show();
    //this->setWindowState(Qt::WindowActive);
    //emit close_self();
}

