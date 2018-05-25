#ifndef SETPARAMETER_H
#define SETPARAMETER_H

#include <QWidget>



class SetParameter : public QWidget
{
    Q_OBJECT

public:
    explicit SetParameter(QWidget *parent = 0);
    ~SetParameter();

signals:
    void open_check();
    void open_process();
    void open_setmdole();
    void open_clean();

    void close_self();

private slots:

    void on_pushClean_clicked();

    void on_pushCheck_clicked();

    void on_pushSetmodel_clicked();

    void on_pushProcess_clicked();

    void show_me();


};

#endif // SETPARAMETER_H
