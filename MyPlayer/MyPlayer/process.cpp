#include "process.h"
#include <QPainter>
#include <QDebug>
#include <QString>
#include <QDateTime>

Process::Process(QWidget *parent)
{
   // ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏


}

Process::~Process()
{
   // delete ui;
}


void Process::on_pushClean_clicked()
{
    //this->hide();
    emit open_clean();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Process::on_pushCheck_clicked()
{
    //this->hide();
    emit open_check();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Process::on_pushSetmodel_clicked()
{
    //this->hide();
    emit open_setmdole();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Process::on_pushSetParameter_clicked()
{
    //this->hide();
    emit open_setparameter();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Process::show_me(){
    //this->setWindowFlags(Qt::WindowModal);

    this->show();
    //this->setWindowState(Qt::WindowActive);
    //emit close_self();

}
