#ifndef CLEAN_H
#define CLEAN_H

#include <QWidget>
#include <QTimer>

class Clean : public QWidget
{
    Q_OBJECT

public:
    explicit Clean(QWidget *parent = 0);
    ~Clean();

private slots:


    void on_pushSetp_clicked();

    void on_pushCheck_clicked();

    void on_pushSetm_clicked();

    void on_pushProcess_clicked();

    void show_me();

signals:
    void open_check();
    void open_process();
    void open_setmdole();
    void open_setparameter();

    void close_self();


private:

};

#endif // CLEAN_H
