#include "my_thread.h"
#include <windows.h>
#include <QDebug>

My_thread::My_thread()
{
    qwidget = new QWidget();
    flag = 0;
}

My_thread::~My_thread()
{

}

void My_thread::run(){
    while(1){
//        if(flag == 1){
//            sleep(500);
//            qwidget->close();
//            flag = 0;
//        }

        //qDebug() << "thread print";
    }
}

void My_thread::close_window(){
    qwidget = (QWidget *)sender();
    qwidget->close();
}
