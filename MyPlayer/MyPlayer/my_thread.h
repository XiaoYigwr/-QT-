#ifndef MY_THREAD_H
#define MY_THREAD_H
#include <QThread>
#include <QWidget>

class My_thread : public QThread
{
    Q_OBJECT
public:
    My_thread();
    ~My_thread();

protected:
    void run();

private slots:
    void close_window();


public:
    QWidget *qwidget;
    int flag;
};

#endif // MY_THREAD_H
