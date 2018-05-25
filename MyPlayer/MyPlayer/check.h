#ifndef CHECK_H
#define CHECK_H

#include <QWidget>
class Check : public QWidget
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = 0);
    ~Check();

signals:
    void open_clean();
    void open_process();
    void open_setmdole();
    void open_setparameter();

    void close_self();

private slots:
    void on_pushClean_clicked();

    void on_pushSetm_clicked();

    void on_pushProcess_clicked();

    void on_pushSetp_clicked();

    void show_me();


private:

};

#endif // CHECK_H



