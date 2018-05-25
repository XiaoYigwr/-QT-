#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QtWidgets/QMainWindow>
#include <QWidget>
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
#include<qtableview>
#include"mylrc.h"

class MyPlayer : public QWidget
{
	Q_OBJECT

public:
	MyPlayer(QWidget *parent = 0);
	~MyPlayer();


	//转移
	void resolve_lrc(const QString &source_file_name);
	QMap<qint64, QString> lrc_map;
	MyLrc *myLrc;
	QTimer *timer;
	QTimer *backTimer;
	QTableWidget* tablewidget;
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	QPoint dragPos;
	void dislikefile();
	void setCurrentFile(const QString &fileName);
	QString curFile;
	QTimer *timer1;
	int m_time;
	void settime(const unsigned int time0, const unsigned int time, const unsigned int time1);

	void myTrayIcon();//托盘实现
	void on_tableWidget_activated(const QModelIndex &index);




	QPushButton* pauseBtn;//播放和暂停按钮
	QPushButton* backBtn;//上一曲
	QPushButton* nextBtn;//下一曲
	QPushButton* modelBtn;//音乐播放模式选择按钮
	QPushButton* lrcShow;//是否展示桌面歌词按钮
	QPushButton* login;//登录按钮
	QPushButton* pushButton_4;//关闭按钮
	QPushButton* pushButton_5;//最小化按钮
	QPushButton* timeClock;//是否定时按钮
	QLabel* timeLabel;//倒计时时间显示
	QComboBox* timeEdit;//定时时间编辑
	QLabel* lrcLabel;//歌词显示
	QLabel* privouslrc;//上句歌词显示
	QLabel* laterlrc;//下句歌词显示
	QLabel* label_2;//歌曲图片显示
	QSlider* slider;//歌曲进度滑条
	QLabel* musicName;//音乐名字显示
	QLabel* totalTime;//歌曲的总时间显示
	QCheckBox* volumBox;//静音显示
	QPushButton* volumBtn;//静音显示按钮
	QSlider* volumSlider;//声音调节滑动条
	QLabel* currTime;//当前播放时间
	QPushButton* pushButton;//列表按钮
	QPushButton* pushButton_3;//添加歌曲按钮//废弃

	QPushButton* pushButton_8;//下载
	QPushButton* pushButton_9;//电台
	QPushButton* pushButton_10;//添加歌曲
	QPushButton* pushButton_11;//云收藏
	QPushButton* pushButton_12;//设置按钮
	QLabel* label_18;
	QLabel* label_17;
	QLabel* label_16;//关闭按钮
	QLabel* label_15;//最小化
	QLabel* label_14;//小窗口展示，隐藏乐库
	QLabel* label_13;//开启遥控器
	QLabel* label_12;//设置
	QLabel* label_11;//设置皮肤
	QLabel* label_10;//发送消息
	QLabel* label_9;//游戏相关
	QLabel* label_8;//工具箱
	QLabel* label_7;
	QLabel* label_4;//登录用户名
	QLabel* label_3;//用户的头像
	QLabel* label_1;//音乐图标
	QTableWidget* tableWidget;





signals:
	void open_clean();
	void open_process();
	void open_setmdole();
	void open_setparameter();

	void close_self();

private:
	QMediaPlayer *play;
	QMediaPlaylist *playList;

	QSystemTrayIcon *trayIcon;
	QMenu   *trayIconMenu;
	QAction *minimizeAction;
	QAction *restoreAction;
	QAction *quitAction;
	QAction *before;
	QAction *pause;
	QAction *next;
	QAction *aboutus;
	QImage _image;




	void on_pushClean_clicked();

	void on_pushSetm_clicked();

	void on_pushProcess_clicked();

	void on_pushSetp_clicked();

	void show_me();


	private slots :
	void aboutUs();//关于我们
	void trayiconActivated(QSystemTrayIcon::ActivationReason reason);//托盘鼠标响应

	//void backGroungChange();//背景更换
	void pauseBtnClicked();//
	void UpdateTime(qint64 time);//
	void on_lrcShow_clicked();//
	void on_nextBtn_clicked();//
	void on_backBtn_clicked();//
	void btnUpdate();//
	void on_volumBtn_clicked();//
	void on_volumBox_clicked();//
	void on_volumSlider_valueChanged(int value);//
	void on_slider_sliderMoved(int position);//
	void on_pushButton_clicked();//
	void on_pushButton_4_clicked();//
	void on_pushButton_5_clicked();//
	void on_pushButton_3_clicked();//
	void tableClick(int row, int colum);//
	void on_modelBtn_clicked();//
	void on_login_clicked();//
	void on_timeClock_clicked();//
	//定时器退出
	void start(int);//
	void subtime();//
	void showtime();//
	void playTo(int i);

	//void on_tableWidget_activated(const QModelIndex &index);

	//功能函数
	void contextMenuEvent(QContextMenuEvent *event);
	void likefile();
	void deleteSelectedMusic();
	void clearPlaylist();
	void setPosition();



};

#endif // MYPLAYER_H
