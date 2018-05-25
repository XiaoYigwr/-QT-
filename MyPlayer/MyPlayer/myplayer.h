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


	//ת��
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

	void myTrayIcon();//����ʵ��
	void on_tableWidget_activated(const QModelIndex &index);




	QPushButton* pauseBtn;//���ź���ͣ��ť
	QPushButton* backBtn;//��һ��
	QPushButton* nextBtn;//��һ��
	QPushButton* modelBtn;//���ֲ���ģʽѡ��ť
	QPushButton* lrcShow;//�Ƿ�չʾ�����ʰ�ť
	QPushButton* login;//��¼��ť
	QPushButton* pushButton_4;//�رհ�ť
	QPushButton* pushButton_5;//��С����ť
	QPushButton* timeClock;//�Ƿ�ʱ��ť
	QLabel* timeLabel;//����ʱʱ����ʾ
	QComboBox* timeEdit;//��ʱʱ��༭
	QLabel* lrcLabel;//�����ʾ
	QLabel* privouslrc;//�Ͼ�����ʾ
	QLabel* laterlrc;//�¾�����ʾ
	QLabel* label_2;//����ͼƬ��ʾ
	QSlider* slider;//�������Ȼ���
	QLabel* musicName;//����������ʾ
	QLabel* totalTime;//��������ʱ����ʾ
	QCheckBox* volumBox;//������ʾ
	QPushButton* volumBtn;//������ʾ��ť
	QSlider* volumSlider;//�������ڻ�����
	QLabel* currTime;//��ǰ����ʱ��
	QPushButton* pushButton;//�б�ť
	QPushButton* pushButton_3;//��Ӹ�����ť//����

	QPushButton* pushButton_8;//����
	QPushButton* pushButton_9;//��̨
	QPushButton* pushButton_10;//��Ӹ���
	QPushButton* pushButton_11;//���ղ�
	QPushButton* pushButton_12;//���ð�ť
	QLabel* label_18;
	QLabel* label_17;
	QLabel* label_16;//�رհ�ť
	QLabel* label_15;//��С��
	QLabel* label_14;//С����չʾ�������ֿ�
	QLabel* label_13;//����ң����
	QLabel* label_12;//����
	QLabel* label_11;//����Ƥ��
	QLabel* label_10;//������Ϣ
	QLabel* label_9;//��Ϸ���
	QLabel* label_8;//������
	QLabel* label_7;
	QLabel* label_4;//��¼�û���
	QLabel* label_3;//�û���ͷ��
	QLabel* label_1;//����ͼ��
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
	void aboutUs();//��������
	void trayiconActivated(QSystemTrayIcon::ActivationReason reason);//���������Ӧ

	//void backGroungChange();//��������
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
	//��ʱ���˳�
	void start(int);//
	void subtime();//
	void showtime();//
	void playTo(int i);

	//void on_tableWidget_activated(const QModelIndex &index);

	//���ܺ���
	void contextMenuEvent(QContextMenuEvent *event);
	void likefile();
	void deleteSelectedMusic();
	void clearPlaylist();
	void setPosition();



};

#endif // MYPLAYER_H
