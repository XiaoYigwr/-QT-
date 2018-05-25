#ifndef SETMODEL_H
#define SETMODEL_H

#include <QWidget>



class SetModel : public QWidget
{
    Q_OBJECT

public:
    explicit SetModel(QWidget *parent = 0);
    ~SetModel();

signals:
    void open_check();
    void open_clean();
    void open_process();
    void open_setparameter();

    void close_self();

private slots:
    void on_pushClean_clicked();

    void on_pushCheck_clicked();

    void on_pushProcess_clicked();

    void on_pushParameter_clicked();

    void show_me();


private:


};

#endif // SETMODEL_H
