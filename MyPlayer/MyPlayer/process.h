#ifndef PROCESS_H
#define PROCESS_H

#include <QWidget>
#include <QTimer>



class Process : public QWidget
{
    Q_OBJECT

public:
    explicit Process(QWidget *parent = 0);
    ~Process();

signals:
    void open_check();
    void open_clean();
    void open_setmdole();
    void open_setparameter();

    void close_self();



private slots:
    void on_pushClean_clicked();

    void on_pushCheck_clicked();

    void on_pushSetmodel_clicked();

    void on_pushSetParameter_clicked();

    void show_me();                     //显示自己



private:


};

#endif // PROCESS_H
