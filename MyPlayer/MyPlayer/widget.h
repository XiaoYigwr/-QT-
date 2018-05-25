#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QFileDialog>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QFrame>
#include<QTableWidget>
#include<QTableView>
#include<QByteArray>
#include<QMouseEvent>
#include<QPoint>
#include<QTreeWidgetItem>
#include<QSystemTrayIcon>
#include<QComboBox>
#include<QTimer>
#include<QSlider>
#include<qcheckbox>
#include<qdatetime>
#include<qmessagebox>
#include<QApplication>
#include<qsystemtrayicon>
#include<qgridlayout.h>
#include<qimage>
#include<qsizepolicy>
#include "clean.h"
#include "setparameter.h"
#include "setmodel.h"
#include "process.h"
#include "myplayer.h"
#include "my_thread.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();



	QPushButton* pushButton_6;//进入系统按钮
	QPushButton* pushButton_7;
	QLabel* label_5;//welcom to system
	QLabel* label_6;




protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_7_clicked();

    void check_close();
    void clean_close();
    void proc_close();
    void setm_close();
    void setp_close();

private:
    //Ui::Widget *ui;

    Clean *clean;
    SetParameter *setp;
    SetModel *setm;
    Process *proc;
    MyPlayer *myplayer;

    My_thread *thread;
};

#endif // WIDGET_H
