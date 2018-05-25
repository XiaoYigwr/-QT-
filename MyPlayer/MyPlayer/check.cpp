#include "check.h"
//#include <unistd.h>























Check::Check(QWidget *parent) 
{

   // this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
	this->setMinimumSize(1000, 600);
}

Check::~Check()
{
    //delete ui;
}

void Check::on_pushClean_clicked()
{
    //this->hide();
    emit open_clean();
    emit close_self();

    //sleep(50);
    //this->hide();

}

void Check::on_pushSetm_clicked()
{
    //this->hide();
    emit open_setmdole();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Check::on_pushProcess_clicked()
{
    //this->hide();
    emit open_process();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void Check::on_pushSetp_clicked()
{

    emit open_setparameter();
    emit close_self();
    //sleep(50);
    //this->hide();

}

//setWindowFlags( Qt::WindowStaysOnTopHint);
//setWindowFlags(Qt::WindowModal);

void Check::show_me(){

    this->show();
    //this->setWindowState(Qt::WindowActive);

    //emit close_self();
}

