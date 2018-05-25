#include "widget.h"
//#include "ui_widget.h"
#include <QPainter>

#include <QPainterPath>

#include <QDebug>
#include <QString>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QPixmap>
#include<QPalette>
#include<QPainter>
#include<QColor>
#include<QHeaderView>
#include<QToolBar>


Widget::Widget(QWidget *parent)
{
    //ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
	this->setMinimumSize(600 * 1.4, 350 * 1.4);
	
	QPalette palette;
	palette.setBrush(QPalette::Background, QBrush(QPixmap(":/new/prefix1/Resources/skin/1.jpg")));
	this->setAutoFillBackground(true);
	this->setPalette(palette);
	
    clean = new Clean();
    setp = new SetParameter();
    setm = new SetModel();
    proc = new Process();
    myplayer = new MyPlayer();

    thread = new My_thread();
    thread->start();



    connect(myplayer,SIGNAL(open_clean()),clean,SLOT(show_me()));
    connect(myplayer,SIGNAL(open_setmdole()),setm,SLOT(show_me()));
    connect(myplayer,SIGNAL(open_process()),proc,SLOT(show_me()));
    connect(myplayer,SIGNAL(open_setparameter()),setp,SLOT(show_me()));

    connect(clean,SIGNAL(open_check()),myplayer,SLOT(show_me()));
    connect(clean,SIGNAL(open_setmdole()),setm,SLOT(show_me()));
    connect(clean,SIGNAL(open_process()),proc,SLOT(show_me()));
    connect(clean,SIGNAL(open_setparameter()),setp,SLOT(show_me()));

    connect(proc,SIGNAL(open_check()),myplayer,SLOT(show_me()));
    connect(proc,SIGNAL(open_setmdole()),setm,SLOT(show_me()));
    connect(proc,SIGNAL(open_clean()),clean,SLOT(show_me()));
    connect(proc,SIGNAL(open_setparameter()),setp,SLOT(show_me()));

    connect(setm,SIGNAL(open_check()),myplayer,SLOT(show_me()));
    connect(setm,SIGNAL(open_setparameter()),setp,SLOT(show_me()));
    connect(setm,SIGNAL(open_clean()),clean,SLOT(show_me()));
    connect(setm,SIGNAL(open_process()),proc,SLOT(show_me()));

    connect(setp,SIGNAL(open_check()),myplayer,SLOT(show_me()));
    connect(setp,SIGNAL(open_setmdole()),setm,SLOT(show_me()));
    connect(setp,SIGNAL(open_clean()),clean,SLOT(show_me()));
    connect(setp,SIGNAL(open_process()),proc,SLOT(show_me()));

    //各界面关闭信号和槽连接
//    connect(check,SIGNAL(close_self()),this,SLOT(check_close()));
//    connect(clean,SIGNAL(close_self()),this,SLOT(clean_close()));
//    connect(proc,SIGNAL(close_self()),this,SLOT(proc_close()));
//    connect(setm,SIGNAL(close_self()),this,SLOT(setm_close()));
//    connect(setp,SIGNAL(close_self()),this,SLOT(setp_close()));



    connect(myplayer,SIGNAL(close_self()),thread,SLOT(close_window()),Qt::QueuedConnection);
    connect(clean,SIGNAL(close_self()),thread,SLOT(close_window()),Qt::QueuedConnection);
    connect(proc,SIGNAL(close_self()),thread,SLOT(close_window()),Qt::QueuedConnection);
    connect(setm,SIGNAL(close_self()),thread,SLOT(close_window()),Qt::QueuedConnection);
    connect(setp,SIGNAL(close_self()),thread,SLOT(close_window()),Qt::QueuedConnection);




}

Widget::~Widget()
{
   // delete ui;
}

void Widget::paintEvent(QPaintEvent *){
    QPainter painter1(this);
    painter1.setPen(QPen(Qt::blue));
    painter1.setBrush(QBrush(Qt::blue));

	QFont font2;
	font2.setFamily("宋体");
	font2.setPointSize(50);
	painter1.setFont(font2);
	painter1.drawText(270, 100, tr("Welcome To"));

    QFont font3;
    font3.setFamily("宋体");
    font3.setPointSize(60);
    painter1.setFont(font3);
    painter1.drawText(120,200,tr("My Music Player"));
	
	QPainter painter3(this);
	painter3.setPen(QPen(Qt::white));
	painter3.setBrush(QBrush(Qt::blue));


	QFont font4;
	font4.setFamily("宋体");
	font4.setPointSize(30);
	painter3.setFont(font4);
	painter3.drawText(250, 260, tr("XingHeng@Guowenrui"));
    //painter.drawText(310,300,QStringLiteral("云影星痕郭文瑞"));//文字输入有常量无法正常显示
	
	
	label_6 = new QLabel;
	label_6->setText(QString());
	label_6->setAttribute(Qt::WA_TranslucentBackground);
	label_6->setAlignment(Qt::AlignCenter);
	label_6->setFont(font2);
	//musicName->setText(QStringLiteral("歌曲名"));
	label_5= new QLabel;
	//label_3->setObjectName(QStringLiteral("label_3"));
	//label_3->setGeometry(QRect(30, 20, 61, 61));
	label_5->setStyleSheet(QStringLiteral(""));
	label_5->setText(QStringLiteral(""));
	//label_5->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Resources/head.png")));

	pushButton_6 = new QPushButton;
	pushButton_6->setToolTip(tr("Phone model"));
	pushButton_6->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (3).png);"));
	pushButton_6->setText(QString());
	/*
	pushButton_6->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (3).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (3).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (3).png);}"
		"QPushButton:focus{padding:-1;}");*/
	pushButton_6->setFlat(false);//false为点击时高亮


	pushButton_7 = new QPushButton;
	pushButton_7->setToolTip(tr("Win model"));
	pushButton_7->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (3).png);"));
	pushButton_7->setText(QString());
	/*
	pushButton_7->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (3).png.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (3).png.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (3).png.png);}"
		"QPushButton:focus{padding:-1;}");
		*/
	
	pushButton_7->setFlat(false);//false为点击时高亮




	QGridLayout *pLayout1 = new QGridLayout();
	//label_5->setFixedHeight(2);
	//label_5->setFixedWidth(250);
	pLayout1->addWidget(label_5, 1, 1, 3, 137, Qt::AlignCenter);

	pLayout1->addWidget(label_6, 8, 10, 10, 20);//第十七行扩展完毕

	pushButton_6->setFixedHeight(40);
	pushButton_6->setFixedWidth(40);
	pLayout1->addWidget(pushButton_6, 19, 30, 5, 5);

	pushButton_7->setFixedHeight(40);
	pushButton_7->setFixedWidth(40);
	pLayout1->addWidget(pushButton_7, 19, 100, 5, 5);

	connect(pushButton_7, SIGNAL(clicked()), this, SLOT(on_pushButton_7_clicked()));

	setLayout(pLayout1);

}

void Widget::on_pushButton_7_clicked()
{
    //this->hide();
    //this->setWindowState(Qt::WindowActive);
    myplayer->show();
    this->close();

}

void Widget::check_close(){
    myplayer->close();
}

void Widget::clean_close(){
    clean->close();
}

void Widget::proc_close(){
    proc->close();
}


void Widget::setm_close(){
    setm->close();
}

void Widget::setp_close(){
    setp->close();
}
