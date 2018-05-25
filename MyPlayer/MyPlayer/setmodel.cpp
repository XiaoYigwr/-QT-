#include "setmodel.h"

SetModel::SetModel(QWidget *parent)
{
    //ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

SetModel::~SetModel()
{
  //  delete ui;
}

void SetModel::on_pushClean_clicked()
{
    //this->hide();
    emit open_clean();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetModel::on_pushCheck_clicked()
{
    //this->hide();
    emit open_check();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetModel::on_pushProcess_clicked()
{
    //this->hide();
    emit open_process();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetModel::on_pushParameter_clicked()
{
    //this->hide();
    emit open_setparameter();
    emit close_self();
    //sleep(50);
    //this->hide();

}

void SetModel::show_me(){
    //this->setWindowFlags(Qt::WindowModal);

    this->show();
    //this->setWindowState(Qt::WindowActive);
    //emit close_self();

}

