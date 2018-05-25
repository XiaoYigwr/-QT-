#include "myplayer.h"

MyPlayer::MyPlayer(QWidget *parent)
{
	//ui.setupUi(this);

	trayIcon = new QSystemTrayIcon(this);
	this->setMinimumSize(960, 600);
	this->setWindowFlags(Qt::FramelessWindowHint);//ȡ��������

	
	QPalette palette;
	palette.setBrush(QPalette::Background, QBrush(QPixmap(":/new/prefix1/Resources/skin/1.jpg")));
	this->setAutoFillBackground(true);
	this->setPalette(palette);
	this->setWindowTitle("Mymusic");

	//�û�ͷ��
	label_3 = new QLabel;
	label_3->setStyleSheet(QStringLiteral(""));
	label_3->setText(QString());
	label_3->setAttribute(Qt::WA_TranslucentBackground);

	
	label_3->setFixedHeight(30);
	label_3->setFixedWidth(30);
	
	QGridLayout* pLayout2 = new QGridLayout();
	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap1 = new QPixmap(":/new/prefix1/Resources/mymusic/head.png");
	pixmap1->scaled(label_3->size(), Qt::KeepAspectRatio);
	label_3->setScaledContents(true);
	label_3->setPixmap(*pixmap1);
	pLayout2->addWidget(label_3, 0, 0, 1, 1, Qt::AlignCenter);


	//��¼�û���
	label_4 = new QLabel;
	label_4->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", 0));
	//label_4->setText(QStringLiteral("�û�����"));
	label_4->setFixedHeight(38);
	label_4->setFixedWidth(40);
	QGridLayout* pLayout3 = new QGridLayout();
	pLayout2->addWidget(label_4, 0, 1, 1, 3, Qt::AlignHCenter);


	//��¼��ť
	login = new QPushButton;
	login->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/denglu.png);"));

	login->setText(QString());
	login->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/denglu_2.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/denglu.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/denglu_2.png);}"
		"QPushButton:focus{padding:-1;}");
	login->setFixedHeight(20);
	login->setFixedWidth(50);
	//ˮƽ���󣬴�ֱ����
	pLayout2->addWidget(login, 0, 4, 1, 3, Qt::AlignLeft);//��8�в������

	//ˢ�°�ť
	label_7 = new QLabel;
	label_7->setStyleSheet(QStringLiteral(""));
	label_7->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_7->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_refresh(1).png);"));
	//�ƺ�û��������
	label_7->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_refresh(1).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_refresh(2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_refresh(1).png;}"
		"QPushButton:focus{padding:-1;}");

	label_7->setFixedHeight(20);
	label_7->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap2 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_refresh(1).png");
	pixmap2->scaled(label_7->size(), Qt::KeepAspectRatio);
	label_7->setScaledContents(true);
	label_7->setPixmap(*pixmap2);
	pLayout2->addWidget(label_7, 0, 14, 1, 1, Qt::AlignCenter);



	//��ʱ��,�������ع���
	timeEdit = new QComboBox;
	timeEdit->clear();
	timeEdit->insertItems(0, QStringList()
		<< QApplication::translate("Widget", "\350\257\267\351\200\211\346\213\251\346\227\266\351\227\264", 0)
		<< QApplication::translate("Widget", "1", 0)
		<< QApplication::translate("Widget", "3", 0)
		<< QApplication::translate("Widget", "5", 0)
		<< QApplication::translate("Widget", "10", 0)
		<< QApplication::translate("Widget", "30", 0));
	timeEdit->setAttribute(Qt::WA_TranslucentBackground);
	timeLabel = new QLabel;
	timeLabel->setText(QApplication::translate("Widget", "\345\200\222\350\256\241\346\227\266:", 0));
	timeLabel->setAttribute(Qt::WA_TranslucentBackground);
	timeLabel->hide();
	timeEdit->hide();
	//��ʱ
	timer = new QTimer;
	connect(timer, SIGNAL(timeout()), this, SLOT(setPosition()));

	timeLabel->setFixedHeight(38);
	timeLabel->setFixedWidth(50);
	pLayout2->addWidget(timeLabel, 0, 23, 1, 5);

	timeEdit->setFixedHeight(21);
	timeEdit->setFixedWidth(85);
	pLayout2->addWidget(timeEdit, 0, 32, 1, 7);


	//
	label_8 = new QLabel;

	label_8->setStyleSheet(QStringLiteral(""));
	label_8->setText(QString());
	//label_8->setAttribute(Qt::WA_TranslucentBackground);
	label_8->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_tool (2).png.png);"));
	
	//�ƺ�û��������
	/*
	label_8->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_tool (1).png.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_tool (2).png.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_tool (1).png.png;}"
		"QPushButton:focus{padding:-1;}");
		*/

	label_8->setFixedHeight(20);
	label_8->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap3 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_tool (2).png.png");
	pixmap3->scaled(label_8->size(), Qt::KeepAspectRatio);
	label_8->setScaledContents(true);
	label_8->setPixmap(*pixmap3);
	pLayout2->addWidget(label_8, 0, 41, 1, 1, Qt::AlignCenter);





	label_9 = new QLabel;

	label_9->setStyleSheet(QStringLiteral(""));
	label_9->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_9->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_game (2).png);"));
	//�ƺ�û��������
	label_9->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_game (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_game (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_game (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_9->setFixedHeight(20);
	label_9->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap4 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_game (2).png");
	pixmap4->scaled(label_9->size(), Qt::KeepAspectRatio);
	label_9->setScaledContents(true);
	label_9->setPixmap(*pixmap4);
	pLayout2->addWidget(label_9, 0, 42, 1, 1, Qt::AlignCenter);





	label_10 = new QLabel;
	label_10->setStyleSheet(QStringLiteral(""));
	label_10->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_10->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_message (2).png);"));
	//�ƺ�û��������
	label_10->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_message (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_message (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_message (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_10->setFixedHeight(20);
	label_10->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap5 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_message (2).png");
	pixmap5->scaled(label_10->size(), Qt::KeepAspectRatio);
	label_10->setScaledContents(true);
	label_10->setPixmap(*pixmap5);
	pLayout2->addWidget(label_10, 0, 43, 1, 1, Qt::AlignCenter);




	label_11 = new QLabel;

	label_11->setStyleSheet(QStringLiteral(""));
	label_11->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_11->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_skin (2).png);"));
	//�ƺ�û��������
	label_11->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_skin (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_skin (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_skin (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_11->setFixedHeight(20);
	label_11->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap6 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_skin (2).png");
	pixmap6->scaled(label_11->size(), Qt::KeepAspectRatio);
	label_11->setScaledContents(true);
	label_11->setPixmap(*pixmap6);
	pLayout2->addWidget(label_11, 0, 44, 1, 1, Qt::AlignCenter);

	/*
	label_12 = new QLabel;
	label_12->setStyleSheet(QStringLiteral(""));
	label_12->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_12->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_setting (2).png);"));
	//�ƺ�û��������
	label_12->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_setting (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_setting (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_setting (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_12->setFixedHeight(20);
	label_12->setFixedWidth(20);*/

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	/*QPixmap *pixmap7 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_setting (2).png");
	pixmap7->scaled(label_12->size(), Qt::KeepAspectRatio);
	label_12->setScaledContents(true);
	label_12->setPixmap(*pixmap7);
	pLayout2->addWidget(label_12, 0, 45, 1, 1, Qt::AlignCenter);*/

	pushButton_12 = new QPushButton;
	pushButton_12->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_setting (2).png);"));
	pushButton_12->setText(QString());
	pushButton_12->setFixedHeight(20);
	pushButton_12->setFixedWidth(20);
	pLayout2->addWidget(pushButton_12, 0, 45, 1, 1, Qt::AlignCenter);

	label_13 = new QLabel;
	label_13->setStyleSheet(QStringLiteral(""));
	label_13->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_13->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_mobile (2).png);"));
	//�ƺ�û��������
	label_13->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_mobile (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_mobile (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_mobile (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_13->setFixedHeight(20);
	label_13->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap8 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_mobile (2).png");
	pixmap8->scaled(label_13->size(), Qt::KeepAspectRatio);
	label_13->setScaledContents(true);
	label_13->setPixmap(*pixmap8);
	pLayout2->addWidget(label_13, 0, 46, 1, 1, Qt::AlignCenter);


	label_14 = new QLabel;
	label_14->setStyleSheet(QStringLiteral(""));
	label_14->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_14->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_miniframe (2).png);"));
	//�ƺ�û��������
	label_14->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_miniframe (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_miniframe (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_miniframe (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_14->setFixedHeight(20);
	label_14->setFixedWidth(20);

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	QPixmap *pixmap9 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_miniframe (2).png");
	pixmap9->scaled(label_14->size(), Qt::KeepAspectRatio);
	label_14->setScaledContents(true);
	label_14->setPixmap(*pixmap9);
	pLayout2->addWidget(label_14, 0, 47, 1, 1, Qt::AlignCenter);



	/*
	label_15 = new QLabel;
	label_15->setStyleSheet(QStringLiteral(""));
	label_15->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_15->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_mini (2).png);"));
	//�ƺ�û��������
	label_15->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_mini (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_mini (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_mini (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_15->setFixedHeight(20);
	label_15->setFixedWidth(20);*/

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	/*QPixmap *pixmap10 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_mini (2).png");
	pixmap10->scaled(label_15->size(), Qt::KeepAspectRatio);
	label_15->setScaledContents(true);
	label_15->setPixmap(*pixmap10);
	pLayout2->addWidget(label_15, 0, 48, 1, 1, Qt::AlignCenter);*/
	pushButton_5 = new QPushButton;
	pushButton_5->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_mini (2).png);"));
	pushButton_5->setText(QString());
	pushButton_5->setFixedHeight(20);
	pushButton_5->setFixedWidth(20); 
	pLayout2->addWidget(pushButton_5, 0, 48, 1, 1, Qt::AlignCenter);
	/*
	label_16 = new QLabel;
	label_16->setStyleSheet(QStringLiteral(""));
	label_16->setText(QString());
	//label_7->setAttribute(Qt::WA_TranslucentBackground);
	label_16->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_close (2).png);"));
	//�ƺ�û��������
	label_16->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_close (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/topwidget/btn_close (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/topwidget/btn_close (2).png);}"
		"QPushButton:focus{padding:-1;}");

	label_16->setFixedHeight(20);
	label_16->setFixedWidth(20);*/

	/**************������ʹ����ʹ��ͼƬ��Ӧlabel�Ĵ�С��������*****************/
	/*QPixmap *pixmap11 = new QPixmap(":/new/prefix1/Resources/topwidget/btn_close (2).png");
	pixmap11->scaled(label_16->size(), Qt::KeepAspectRatio);
	label_16->setScaledContents(true);
	label_16->setPixmap(*pixmap11);
	pLayout2->addWidget(label_16, 0, 49, 1, 1, Qt::AlignCenter);
	*/
	pushButton_4 = new QPushButton;
	pushButton_4->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/topwidget/btn_close (2).png);"));
	pushButton_4->setText(QString());
	pushButton_4->setFixedHeight(20);
	pushButton_4->setFixedWidth(20);
	pLayout2->addWidget(pushButton_4, 0, 49, 1, 1, Qt::AlignCenter);

	//�����б�
	pushButton = new QPushButton;
	pushButton->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (2).png);"));
	pushButton->setText(QString());
	pushButton->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (3).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_music (2).png);}"
		"QPushButton:focus{padding:-1;}");

	pushButton->setFixedHeight(20);
	pushButton->setFixedWidth(22);
	pLayout2->addWidget(pushButton, 3, 0, 1, 2,Qt::AlignCenter);
	/*
	//��Ӹ�����ť
	pushButton_3 = new QPushButton;
	//pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
	//pushButton_3->setGeometry(QRect(80, 420, 61, 21));
	pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_cross (1).png);"));
	pushButton_3->setText(QString());

	pushButton_3->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_cross (1).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_cross (2).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_cross (1).png);}"
		"QPushButton:focus{padding:-1;}");


	pushButton_3->setFixedHeight(20);
	pushButton_3->setFixedWidth(20);
	pLayout2->addWidget(pushButton_3, 3, 2, 1, 1, Qt::AlignCenter);

	*/

	//��Ӹ���
	pushButton_10 = new QPushButton;
	//pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
	//pushButton_3->setGeometry(QRect(80, 420, 61, 21));
	pushButton_10->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (2).png);"));
	pushButton_10->setText(QString());

	pushButton_10->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (3).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_phone (2).png);}"
		"QPushButton:focus{padding:-1;}");


	pushButton_10->setFixedHeight(20);
	pushButton_10->setFixedWidth(20);
	pLayout2->addWidget(pushButton_10, 3, 2, 1, 2, Qt::AlignCenter);



	//���ղذ�ť
	pushButton_8 = new QPushButton;
	//pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
	//pushButton_3->setGeometry(QRect(80, 420, 61, 21));
	pushButton_8->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_cloud (2).png);"));
	pushButton_8->setText(QString());

	pushButton_8->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_cloud (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_cloud (3).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_cloud (2).png);}"
		"QPushButton:focus{padding:-1;}"); 


	pushButton_8->setFixedHeight(20);
	pushButton_8->setFixedWidth(20);
	pLayout2->addWidget(pushButton_8, 3, 4, 1, 2, Qt::AlignCenter);



	//��̨����
	pushButton_9 = new QPushButton;
	//pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
	//pushButton_3->setGeometry(QRect(80, 420, 61, 21));
	pushButton_9->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_radio (2).png);"));
	pushButton_9->setText(QString());

	pushButton_9->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_radio (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_radio (3).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_radio (2).png);}"
		"QPushButton:focus{padding:-1;}");


	pushButton_9->setFixedHeight(20);
	pushButton_9->setFixedWidth(20);
	pLayout2->addWidget(pushButton_9, 3, 7, 1, 2, Qt::AlignCenter);




	//����
	pushButton_11 = new QPushButton;
	//pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
	//pushButton_3->setGeometry(QRect(80, 420, 61, 21));
	pushButton_11->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/middlewidget/btn_download (2).png);"));
	pushButton_11->setText(QString());

	pushButton_11->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_download (2).png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/middlewidget/btn_download (3).png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/middlewidget/btn_download (2).png);}"
		"QPushButton:focus{padding:-1;}");


	pushButton_11->setFixedHeight(20);
	pushButton_11->setFixedWidth(20);
	pLayout2->addWidget(pushButton_11, 3, 10, 1, 2, Qt::AlignCenter);



	/**************************�˴�ʡ����7����ť**********************************/

	//�ֿ�
	//��̨
	//�赥
	//MV
	//ֱ��
	//KTV
	//���
	//�����ڵ�����








	/*************�����п�ʼ���ָ�ʲ���***************/
	
	QFont font;
	font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font.setPointSize(10);
	//������
	musicName = new QLabel;
	musicName->setText(QString());
	musicName->setAttribute(Qt::WA_TranslucentBackground);
	musicName->setAlignment(Qt::AlignCenter);
	musicName->setFont(font);
	musicName->setText(QStringLiteral("������"));
	pLayout2->addWidget(musicName, 5, 17, 1, 30, Qt::AlignVCenter | Qt::AlignCenter);


	//ǰһ����

	privouslrc = new QLabel;
	privouslrc->setText(QString());
	privouslrc->setText(QString());
	privouslrc->setAttribute(Qt::WA_TranslucentBackground);
	privouslrc->setFont(font);
	privouslrc->setAlignment(Qt::AlignCenter);
	privouslrc->setStyleSheet("color: rgb(255,255,255)");
	pLayout2->addWidget(privouslrc, 6, 17, 2, 30, Qt::AlignVCenter | Qt::AlignCenter);
	
	
	//�м���
	QFont font1;
	font1.setBold(true);
	font1.setPointSize(20);
	lrcLabel = new QLabel;
	lrcLabel->setText(QString());
	lrcLabel->setAttribute(Qt::WA_TranslucentBackground);
	lrcLabel->setFont(font1);
	lrcLabel->setAlignment(Qt::AlignCenter);
	lrcLabel->setStyleSheet("color: rgb(56, 212, 255)");
	pLayout2->addWidget(lrcLabel, 8, 17, 2, 30, Qt::AlignVCenter | Qt::AlignCenter);
	
	
	//��һ����
	laterlrc = new QLabel;
	laterlrc->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Resources/mymusic/maomi1.png")));
	laterlrc->setText(QString());
	laterlrc->setAttribute(Qt::WA_TranslucentBackground);
	laterlrc->setAlignment(Qt::AlignCenter);
	laterlrc->setFont(font);
	laterlrc->setStyleSheet("color: rgb(255,255,255)");
	pLayout2->addWidget(laterlrc, 10, 17, 2, 30, Qt::AlignVCenter | Qt::AlignCenter);


	/******������һ�еĲ���*******/
	//���ֲ��Ű�ť�˵�����

	pauseBtn = new QPushButton;
	//pauseBtn->setObjectName(QStringLiteral("pauseBtn"));
	//pauseBtn->setGeometry(QRect(350, 390, 61, 61));
	pauseBtn->setStatusTip(QStringLiteral("����"));
	pauseBtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/play_hover.png);"));
	pauseBtn->setFlat(false);//falseΪ���ʱ����
	pauseBtn->setText(QString());
	pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/play_hover.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/icon/mymusic/play_hover.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/play_hover.png);}"
		"QPushButton:focus{padding:-1;}");
	pauseBtn->setFixedHeight(45);
	pauseBtn->setFixedWidth(45);
	pLayout2->addWidget(pauseBtn, 13, 2, 2, 2);



	backBtn = new QPushButton;
	backBtn->setToolTip(QStringLiteral("��һ��"));
	//backBtn->setObjectName(QStringLiteral("backBtn"));
	//backBtn->setGeometry(QRect(270, 395, 51, 51));
	backBtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/prev_hover1.png);"));
	backBtn->setFlat(false);
	backBtn->setText(QString());
	backBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/prev_hover1.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/prev_hover.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/prev_hover1.png);}"
		"QPushButton:focus{padding:-1;}");
	backBtn->setFixedHeight(40);
	backBtn->setFixedWidth(40);
	pLayout2->addWidget(backBtn, 13, 0, 2, 2);//��15����չ���


	nextBtn = new QPushButton;
	nextBtn->setToolTip(QStringLiteral("��һ��"));
	//nextBtn->setObjectName(QStringLiteral("nextBtn"));
	//nextBtn->setGeometry(QRect(440, 395, 51, 51));
	nextBtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/next_hover1.png);"));
	nextBtn->setFlat(false);
	nextBtn->setText(QString());
	nextBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/next_hover1.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/next_hover.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/next_hover1.png);}"
		"QPushButton:focus{padding:-1;}");
	nextBtn->setFixedHeight(40);
	nextBtn->setFixedWidth(40);
	pLayout2->addWidget(nextBtn, 13, 4, 2, 2);//��15����չ��� ��5����չ���


	currTime = new QLabel;
	currTime->setText(QApplication::translate("Widget", "00:00", 0));
	currTime->setAttribute(Qt::WA_TranslucentBackground);
	currTime->setFixedHeight(10);
	currTime->setFixedWidth(30);
	pLayout2->addWidget(currTime, 13, 6, 2, 2);//��15����չ��� ��5����չ���



	//���ֽ��Ȼ���������


	slider = new QSlider;
	//slider->setObjectName(QStringLiteral("slider"));
	slider->setEnabled(true);
	//slider->setGeometry(QRect(130, 350, 571, 21));
	slider->setOrientation(Qt::Horizontal);
	slider->setFixedHeight(6);
	//slider->setFixedWidth(40);
	pLayout2->addWidget(slider, 13, 8, 2, 23);//��30����չ���

	totalTime = new QLabel;
	totalTime->setText(QApplication::translate("Widget", "00:00", 0));
	totalTime->setAttribute(Qt::WA_TranslucentBackground);
	totalTime->setFixedHeight(10);
	totalTime->setFixedWidth(30);
	pLayout2->addWidget(totalTime, 13, 31, 2, 2, Qt::AlignVCenter);//��15����չ��� ��5����չ���

	volumBtn = new QPushButton;
	//volumBtn->setObjectName(QStringLiteral("volumBtn"));
	//volumBtn->setGeometry(QRect(10, 350, 21, 23));
	volumBtn->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Resources/mymusic/mute_4.png);\n"
		"border-image: url(:/new/prefix1/Resources/mymusic/mute_1.png);"));
	volumBtn->setText(QString());
	volumBtn->setFixedHeight(20);
	volumBtn->setFixedWidth(20);
	pLayout2->addWidget(volumBtn, 13, 34, 2, 2);



	volumBox = new QCheckBox;
	volumBox->setText(QApplication::translate("Widget", "\351\235\231\351\237\263", 0));
	volumBox->setAttribute(Qt::WA_TranslucentBackground);
	volumBox->setCursor(QCursor(Qt::PointingHandCursor));
	volumBox->setText(QStringLiteral("����"));
	volumBox->setCheckable(true);
	volumBox->setChecked(false);
	volumBox->setVisible(false);
	volumBox->setFixedHeight(20);
	volumBox->setFixedWidth(45);
	pLayout2->addWidget(volumBox, 13, 36, 2, 4);




	volumSlider = new QSlider;
	//volumSlider->setObjectName(QStringLiteral("volumSlider"));
	//volumSlider->setGeometry(QRect(10, 150, 21, 160));
	volumSlider->setValue(50);
	volumSlider->setOrientation(Qt::Horizontal);
	volumSlider->setFixedHeight(4);
	volumSlider->setFixedWidth(70);
	pLayout2->addWidget(volumSlider, 13, 40, 2, 6);

	//�Ƿ�ʱ��ť
	/*
	timeClock = new QPushButton;
	//timeClock->setObjectName(QStringLiteral("timeClock"));
	//timeClock->setGeometry(QRect(730, 410, 31, 31));
	timeClock->setContextMenuPolicy(Qt::NoContextMenu);
	timeClock->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/document-open-recent.png);"));
	timeClock->setText(QString());
	timeClock->setFixedHeight(23);
	timeClock->setFixedWidth(23);
	pLayout2->addWidget(timeClock, 13, 45, 2, 2);
	*/
	modelBtn = new QPushButton;
	//modelBtn->setObjectName(QStringLiteral("modelBtn"));
	//modelBtn->setGeometry(QRect(570, 420, 61, 21));
	modelBtn->setToolTip("˳�򲥷�");
	modelBtn->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);"));
	modelBtn->setText(QString());
	modelBtn->setToolTip(QStringLiteral("˳�򲥷�"));
	modelBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);}"
		"QPushButton:focus{padding:-1;}");
	modelBtn->setFixedHeight(20);
	modelBtn->setFixedWidth(50);
	pLayout2->addWidget(modelBtn, 13, 45, 2, 2);//�ڶ��в������

	lrcShow = new QPushButton;
	//lrcShow->setObjectName(QStringLiteral("lrcShow"));
	//lrcShow->setGeometry(QRect(650, 420, 51, 23));
	lrcShow->setToolTip(QStringLiteral("����������"));
	lrcShow->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Resources/mymusic/lrc.png);"));
	lrcShow->setText(QString());
	lrcShow->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/lrc_2.png);}"
		"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/lrc.png);}"
		"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/lrc_2.png);}"
		"QPushButton:focus{padding:-1;}");
	lrcShow->setFixedHeight(20);
	lrcShow->setFixedWidth(50);
	pLayout2->addWidget(lrcShow, 13, 48, 2, 2);//�ڶ��У���10�в������









	//backTimer = new QTimer;
	//connect(backTimer, SIGNAL(timeout()), this, SLOT(backGroungChange()));
	//backTimer->start(3000);
	
	
	/*******************************************************/
	myLrc = new MyLrc();
	play = new QMediaPlayer;
	playList = new QMediaPlaylist;
	//playList->addMedia(QUrl::fromLocalFile("E:\\Learning\\Programing\\Visual Studio\\QTFile\\MyPlayer\\musci\\music\\�Ǹ� - ����.mp3"));
	//playList->addMedia(QUrl::fromLocalFile("E:\\Learning\\Programing\\Visual Studio\\QTFile\\MyPlayer\\musci\\music\\shakira - try everything.mp3"));
	//playList->addMedia(QUrl::fromLocalFile("E:\\Learning\\Programing\\Visual Studio\\QTFile\\MyPlayer\\musci\\music\\Maroon 5 - Maps.mp3"));
	play->setPlaylist(playList);
	play->setVolume(50);

	volumBox->setCursor(QCursor(Qt::PointingHandCursor));
	volumBox->setText(QStringLiteral("����"));
	volumBox->setCheckable(true);
	volumBox->setChecked(false);
	volumBox->setVisible(false);


	slider->setCursor(QCursor(Qt::PointingHandCursor));//������ʾ��������߳���ʱ��ʾΪ����
	slider->setStyleSheet("  \
    QSlider::add-page:Horizontal\
    {  \
        background-color: rgb(87, 97, 106);\
       height:4px;\
    }\
    QSlider::sub-page:Horizontal \
   {\
        background-color: rgb(37, 168, 198);\
        height:4px;\
    }\
   QSlider::groove:Horizontal \
   {\
       background:transparent;\
       height:6px;\
   }\
   QSlider::handle:Horizontal \
   {\
       height:35px;\
       width:22px;\
       border-image: url(:/new/prefix1/Resources/mymusic/progress_thumb_2.png);\
       margin: -8 -6px; \
   }\
   ");
	slider->setSliderPosition(play->position());
	volumSlider->setCursor(QCursor(Qt::PointingHandCursor));
	volumSlider->setRange(1, 100);
	volumSlider->setSliderPosition(play->volume());
	volumSlider->setToolTip("����:50");
	volumSlider->setVisible(false);
	volumSlider->setStyleSheet("  \
                                   \
                                    QSlider::add-page:vertical\
                                    {     \
                                       background-color: rgb(37, 168, 198);\
                                       width:4px;\
                                    }\
                                    QSlider::sub-page:vertical \
                                   {\
                                       background-color: rgb(87, 97, 106);\
                                       width:4px;\
                                    }\
                                   QSlider::groove:vertical \
                                   {\
                                       background:transparent;\
                                       width:6px;\
                                   }\
                                   QSlider::handle:vertical \
                                   {\
                                        height: 22px;\
                                       width:22px;\
                                       border-image: url(:/new/prefix1/Resources/mymusic/progress_thumb_2.png);\
                                        margin: -6 -8px; \
                                    }\
                                   ");
	//������
	tableWidget = new QTableWidget;
	if (tableWidget->columnCount() < 3)
		tableWidget->setColumnCount(3);
	QBrush brush(QColor(216, 162, 0, 255));
	brush.setStyle(Qt::SolidPattern);
	QFont font3;
	font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
	font3.setPointSize(10);
	QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
	__qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
	__qtablewidgetitem->setFont(font3);
	__qtablewidgetitem->setForeground(brush);
	tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
	QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
	__qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
	__qtablewidgetitem1->setFont(font3);
	__qtablewidgetitem1->setForeground(brush);
	tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
	QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
	__qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
	__qtablewidgetitem2->setFont(font3);
	__qtablewidgetitem2->setForeground(brush);
	tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
	tableWidget->setObjectName(QStringLiteral("tableWidget"));
	//tableWidget->setGeometry(QRect(720, 250, 291, 481));
	/*tableWidget->setStyleSheet("QHeaderView {background-color:255,255,255,0 } "
		"QHeaderView::section {background-color:255,255,255,0;"
		"color: 255,255,255,0;padding-left: 4px;border: 0px solid 255,255,255,0;}");*/
	//tableWidget->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));
	tableWidget->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

	QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
	___qtablewidgetitem->setText(QStringLiteral("����"));
	QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
	___qtablewidgetitem1->setText(QStringLiteral("����"));
	QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
	___qtablewidgetitem2->setText(QStringLiteral("����·��"));

	tableWidget->hide();
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	tableWidget->setFixedHeight(420);
	tableWidget->setFixedWidth(250);
	tableWidget->setStyleSheet("background-color:transparent");//���ô���͸��
	//tableWidget->setStyleSheet("QTabWidget::pane{border-top:opx solid#e8f3f9;background:transparent;}");
	pLayout2->addWidget(tableWidget, 4, 0, 10, 14, Qt::AlignTop);

	// ����ˮƽ���
	//pLayout2->setHorizontalSpacing(5);
	// ���ô�ֱ���
	pLayout2->setVerticalSpacing(5);
	// ��������
	pLayout2->setContentsMargins(10, 10, 10, 10);//��������
	setLayout(pLayout2);
	/*
	tablewidget->horizontalHeader()->setStyleSheet("QHeaderView {background-color:255,255,255,0 } "
		"QHeaderView::section {background-color:255,255,255,0;"
		"color: 255,255,255,0;padding-left: 4px;border: 0px solid 255,255,255,0;}");*/
	
	connect(pauseBtn, SIGNAL(clicked()), this, SLOT(pauseBtnClicked()));
	connect(play, SIGNAL(positionChanged(qint64)), this, SLOT(UpdateTime(qint64)));
	connect(play, SIGNAL(metaDataChanged()), this, SLOT(btnUpdate()));
	connect(tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(tableClick(int, int)));
	
	
	//��ʱ���˳�
	timer1 = new QTimer;
	connect(timer1, SIGNAL(timeout()), this, SLOT(subtime()));
	connect(timeEdit, SIGNAL(currentIndexChanged(int)), this, SLOT(start(int)));
	//pushButton_5��С��
	// = new QAction(QStringLiteral(label_15), this);
	connect(pushButton_5, SIGNAL(clicked()), this, SLOT(on_pushButton_5_clicked()));
	//pushButton_4�ر�
	connect(pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
	//pushButton_3��Ӹ�����ť
	connect(pushButton_10, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
	//�б�ť
	connect(pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	connect(pushButton_12, SIGNAL(clicked()), this, SLOT(on_timeClock_clicked()));
	connect(lrcShow, SIGNAL(clicked()), this, SLOT(on_lrcShow_clicked()));



	connect(nextBtn, SIGNAL(clicked()), this, SLOT(on_nextBtn_clicked()));
	connect(backBtn, SIGNAL(clicked()), this, SLOT(on_backBtn_clicked()));
	connect(volumBtn, SIGNAL(clicked()), this, SLOT(on_volumBtn_clicked()));
	connect(volumBox, SIGNAL(clicked()), this, SLOT(on_volumBox_clicked()));

	/********************************ע��ע��ע��*******************************/
	/*
	�˴�������ô�֮ǰһֱû�еõ��������Ҫ�ǻ���Ĳۺ��źŵ����ӳ����˺ܴ�����⣬�Ժ�һ��
	Ҫע��sliderMoved(int)�źţ�valueChanged(int)�źŵ�ʹ��

	��Ҫ�ο��˲���http://blog.csdn.net/u010002704/article/details/40226301
	*/

	connect(volumSlider, SIGNAL(valueChanged(int)), this, SLOT(on_volumSlider_valueChanged(int)));
	connect(slider, SIGNAL(sliderMoved(int)), this, SLOT(on_slider_sliderMoved(int)));


	connect(modelBtn, SIGNAL(clicked()), this, SLOT(on_modelBtn_clicked()));
	connect(login, SIGNAL(clicked()), this, SLOT(on_login_clicked()));
	connect(pushButton_12, SIGNAL(clicked()), this, SLOT(on_pushClean_clicked()));
}

MyPlayer::~MyPlayer()
{


}




void MyPlayer::on_slider_sliderMoved(int position)
{
	play->stop();
	timer->stop();
	//position = slider->value();
	play->setPosition(position);
	timer->start();
	play->play();

	if (pauseBtn->toolTip() == tr("Play"))
	{
		pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover1.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/pause_press.png);}"
			"QPushButton:focus{padding:-1;}");
		pauseBtn->setToolTip("Pause");
	}

}

void MyPlayer::start(int i)
{
	switch (i) {
	case 0:
		timer->stop();
		timeLabel->setText(QStringLiteral("Ĭ��"));
		return;
		break;
	case 1:
		settime(0, 1, 0);
		break;
	case 2:
		settime(0, 3, 0);
		break;
	case 3:
		settime(0, 5, 0);
		break;
	case 4:
		settime(0, 10, 0);
		break;
	case 5:
		settime(0, 30, 0);
		break;
	default:
		break;
	}

	//�趨m_timerΪ1s����һ���ź�
	while (m_time&&!timer1->isActive())
	{
		timer1->start(1000);
	}


}

//��ʾʱ��
void MyPlayer::showtime()
{   //��ʣ��ʱ��ת��Ϊʱ���֣���
	int h = m_time / 3600;
	int m_time1 = m_time % 3600;
	int m = m_time1 / 60;
	int s = m_time1 % 60;

	QTime time = QTime(h, m, s);
	QString text = time.toString("%1:%2:%3").arg(h).arg(m).arg(s);
	timeLabel->setText(text);

	if (m_time <= 0)
	{
		timer1->stop();
		exit(0);
	}


}
//�ύ��ǰʣ��ʱ��
void MyPlayer::subtime()
{
	m_time--;//ʣ��ʱ�����һ��
	showtime();
}

//���õ���ʱ
void MyPlayer::settime(const unsigned int time0, const unsigned int time, const unsigned int time1)
{
	m_time = time0 * 3600 + time * 60 + time1;
}

//���ı���
/*
void MyMPlayer::backGroungChange()
{

QPixmap _image;
_image.load("E:\\Learning\\Programing\\Visual Studio\\QTFile\\MyPlayer\\musci\\images1\\beijing.png");
//this->setAutoFillBackground(true);
backgroud->setPixmap(_image);

//QPixmap pixmap;
//QString path = ":/new/prefix1/background/background_";
//path =  path + QString::number((qrand()%11+1))+".png";
//pixmap.load(path);
//backgroud->setPixmap(pixmap);

}
*/





void MyPlayer::tableClick(int row, int colum)
{
	playList->setCurrentIndex(row + 3);
	//pauseBtnClicked();
	play->play();
}

//�������tableClick�Ĺ�����һ����
void MyPlayer::playTo(int i)
{
	playList->setCurrentIndex(i);
	play->play();
}

void MyPlayer::setPosition()
{
	qint64 position = play->position();
	slider->setMaximum(play->duration());
	slider->setSliderPosition(position);

	//position = slider->value();
	slider->setValue(position);
	QTime duration(0, position / 60000, qRound((position % 60000) / 1000.0));

	qint64 maxPosition = play->duration();
	QTime sumTime(0, maxPosition / 60000, qRound((maxPosition % 60000) / 1000.0));
	totalTime->setText(sumTime.toString(tr("mm:ss")));
	currTime->setText(duration.toString(tr("mm:ss")));

	if (pauseBtn->toolTip() == "Play")
	{
		pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover1.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/pause_press.png);}"
			"QPushButton:focus{padding:-1;}");
		pauseBtn->setToolTip(QStringLiteral("Pause"));
	}

}
void MyPlayer::btnUpdate()
{
	QString title = play->metaData("Title").toString();
	QString author = play->metaData("Author").toString();
	qDebug() << title << author;
	musicName->setText(author + "-" + title);
	resolve_lrc(title);
}

void MyPlayer::likefile()
{
	QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("���Ϊ"), curFile, tr("(*.txt)"));
	if (!fileName.isEmpty())
	{
		QFile file(fileName);
		if (!file.open(QFile::WriteOnly | QFile::Text)){
			QMessageBox::warning(this, QStringLiteral("���û�������б�"), QStringLiteral("�޷�д���ļ� %1:\n%2.").arg(fileName).arg(file.errorString()));
		}
		QTextStream out(&file);
		QApplication::setOverrideCursor(Qt::WaitCursor);
		for (int i = 0; i < tableWidget->rowCount(); i++)
		{
			out << tableWidget->item(i, 2)->text();
			if (i < tableWidget->rowCount() - 1)
				out << endl;
		}
		QApplication::restoreOverrideCursor();
		setCurrentFile(fileName);
	}

}

void MyPlayer::setCurrentFile(const QString &fileName)
{
	// canonicalFilePath()���Գ�ȥ·���еķ������ӣ���.���͡�..���ȷ���
	curFile = QFileInfo(fileName).canonicalFilePath();
	// �ĵ�û�б����Ĺ�
	//savebutton->setDisabled(true);
}

void MyPlayer::dislikefile()
{
	QString initialName = QDir::homePath();
	QString playListFileName = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ���ļ�"), initialName, tr("(*.txt)"));
	bool flag = false;
	if (playList->isEmpty())
		flag = true;
	QFile file(playListFileName);
	QString path;
	if (!file.open(QFile::ReadOnly | QFile::Text))
		QMessageBox::warning(this, QStringLiteral("���û������б�"), QStringLiteral("�޷����ļ� %1:\n%2.").arg(playListFileName).arg(file.errorString()));
	else{
		QTextStream stream(&file);
		int i = 0;
		while (!stream.atEnd()){
			path = stream.readLine();
			playList->addMedia(QUrl::fromLocalFile(path));
			QString fileName = path.split("\\").last();
			int rownum = tableWidget->rowCount();
			tableWidget->insertRow(rownum);
			tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
			tableWidget->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
			tableWidget->setItem(rownum, 2, new QTableWidgetItem(QDir::toNativeSeparators(path)));
			i = i + 1;
		}
		if (i != 0){
			initialName = path.left(path.lastIndexOf('/', -1));
		}
	}

}

////��������:�������
void MyPlayer::resolve_lrc(const QString &source_file_name)
{
	lrc_map.clear();
	//�ж��ļ��Ƿ����
	if (source_file_name.isEmpty())
		return;
	QString lrc_file_name = "E:\\Learning\\Programing\\Visual Studio\\QTFile\\MyPlayer_succeed\\musci\\music\\" + source_file_name + ".lrc";
	//    int index = playList->currentIndex();
	//    QString path = tableWidget->item(index,2)->text();
	//    qDebug()<<path;
	QFile file(lrc_file_name);
	if (!file.open(QIODevice::ReadOnly)){
		lrcLabel->setText(QStringLiteral("δ�ҵ���ƥ����"));
		return;
	}

	//��ȡ�ļ���������
	QString all_text = QString(file.readAll());
	file.close();
	QStringList lrc_line = all_text.split("\n");
	//������ʽd{2}��ʾƥ��2������
	QRegExp rx("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");
	//����
	foreach(QString oneline, lrc_line) {
		QString temp = oneline;
		temp.replace(rx, "");
		int pos = rx.indexIn(oneline, 0);
		while (pos != -1) {
			QString cap = rx.cap(0);//���ص�0�����ʽƥ�������
			// ��ʱ���ǩת��Ϊʱ����ֵ���Ժ���Ϊ��λ
			QRegExp regexp;
			regexp.setPattern("\\d{2}(?=:)");
			regexp.indexIn(cap);
			int minute = regexp.cap(0).toInt();
			regexp.setPattern("\\d{2}(?=\\.)");
			regexp.indexIn(cap);
			int second = regexp.cap(0).toInt();
			regexp.setPattern("\\d{2}(?=\\])");
			regexp.indexIn(cap);
			int millisecond = regexp.cap(0).toInt();
			qint64 totalTime = minute * 60000 + second * 1000 + millisecond * 10;
			lrc_map.insert(totalTime, temp);
			pos += rx.matchedLength();
			pos = rx.indexIn(oneline, pos);//ƥ��ȫ��
		}
	}
	if (lrc_map.isEmpty()){
		lrcLabel->setText(QStringLiteral("δ�ҵ���ƥ����"));
		return;
	}
}
//////�������ʾ��������MyMPlayer��
void MyPlayer::UpdateTime(qint64 time)
{
	qint64 total_time_value = play->duration();
	QTime total_time(0, (total_time_value / 60000) % 60, (total_time_value / 1000) % 60);
	QTime current_time(0, (time / 60000) % 60, (time / 1000) % 60);
	QString str = current_time.toString("mm:ss") + "/" + total_time.toString("mm:ss");
	if (!lrc_map.isEmpty()) {
		// ��ȡ��ǰʱ���ڸ���е�ǰ������ʱ���
		qint64 previous = 0;
		qint64 later = 0;
		//keys()��������lrc_map�б�
		qint64 count = 0;
		foreach(qint64 value, lrc_map.keys()) {
			if (time >= value) {
				count++;
				previous = value;
			}
			else {
				later = value;
				break;
			}
		}

		if (later == 0)
			later = total_time_value;
		qint64 front = 0;
		qint64 front1 = 0;
		qint64 later1;
		qint64 a = 0;
		foreach(qint64 item, lrc_map.keys()) {
			a++;
			if (((a == (count - 1)) && item < previous))
				front = item;
			if (((a == (count - 2)) && item < previous))
				front1 = item;
			if (((a == (count + 2)) && item > previous))
				later1 = item;
		}
		QString frontLrc = lrc_map.value(front) + "\n" + "\n" + lrc_map.value(front1);
		QString later_lrc = lrc_map.value(later) + "\n" + "\n" + lrc_map.value(later1);
		QString current_lrc = lrc_map.value(previous);
		if (current_lrc != myLrc->text()) {
			laterlrc->setText(later_lrc);
			myLrc->setText(current_lrc);
			lrcLabel->setText(current_lrc);

			privouslrc->setText(frontLrc);
			qint64 interval_time = later - previous;
			myLrc->start_lrc_mask(interval_time);
		}
	}
	else {  // ���û�и���ļ������ڶ�����ǩ����ʾ��������
		QString title = play->metaData("Title").toString() + ".mp3";
		musicName->setText(title);
	}
}




void MyPlayer::pauseBtnClicked()
{


	if (pauseBtn->toolTip() == tr("Pause"))
	{
		timer->stop();
		play->pause();
		pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/play_hover.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/play_hover.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/play_pres.png);}"
			"QPushButton:focus{padding:-1;}");
		pauseBtn->setToolTip("Play");
	}
	else
	{
		QString title = play->metaData("Title").toString();
		QString author = play->metaData("Author").toString();
		QString musicname = title + "-" + author;
		musicName->setText(musicname);
		resolve_lrc(title);

		timer->start();
		play->play();
		pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover1.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/pause_press.png);}"
			"QPushButton:focus{padding:-1;}");
		pauseBtn->setToolTip("Pause");//���ܸ��ĸ���Ϊ������ʾ��ť�޷�����

	}

}

void MyPlayer::on_lrcShow_clicked()
{


	if (myLrc->isHidden())
		myLrc->show();
	else
		myLrc->hide();
}

void MyPlayer::on_nextBtn_clicked()
{
	//playList->next();

	int currentIndex = playList->currentIndex();
	if (++currentIndex == playList->mediaCount())
		currentIndex = 0;
	playList->setCurrentIndex(currentIndex);

	if (pauseBtn->toolTip() == tr("Play"))
	{
		pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover1.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/pause_press.png);}"
			"QPushButton:focus{padding:-1;}");
		pauseBtn->setToolTip("Pause");
	}
	timer->start();
	play->play();
	//updaInfo();
	QString title = play->metaData("Title").toString();
	QString author = play->metaData("Author").toString();
	QString musicname = title + "-" + author;
	qDebug() << title;
	musicName->setText(musicname);
	resolve_lrc(title);
}


void MyPlayer::on_backBtn_clicked()
{
	play->stop();
	playList->previous();

	if (pauseBtn->toolTip() == tr("Play"))
	{
		pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover1.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/pause_hover.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/pause_press.png);}"
			"QPushButton:focus{padding:-1;}");
		pauseBtn->setToolTip("Pause");
	}
	timer->start();
	play->play();
	QString title = play->metaData("Title").toString();
	QString author = play->metaData("Author").toString();
	QString musicname = title + "-" + author;
	qDebug() << title;
	musicName->setText(musicname);
	resolve_lrc(title);

}

void MyPlayer::on_volumBtn_clicked()
{
	if (volumSlider->isVisible() && volumBox->isVisible())
	{
		volumSlider->setVisible(false);
		volumBox->setVisible(false);
	}
	else
	{
		volumSlider->setVisible(true);
		volumBox->setVisible(true);
	}
}


void MyPlayer::on_volumBox_clicked()
{
	if (volumBox->isChecked())
	{
		play->setVolume(0);
		volumBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/mute_2.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/mute_2.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mute_2.png);}"
			"QPushButton:focus{padding:-1;}");

		volumBox->setToolTip(QStringLiteral("����"));
		volumBtn->setToolTip(QStringLiteral("����"));
	}
	else
	{
		play->setVolume(volumSlider->value());
		volumBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/mute_1.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/mute_1.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/mute_1.png);}"
			"QPushButton:focus{padding:-1;}");

		QString valueStr = QString("%1").arg(volumSlider->value());
		volumBox->setToolTip(QStringLiteral("����:") + valueStr);
		volumBtn->setToolTip(QStringLiteral("����:") + valueStr);
	}
}

void MyPlayer::on_volumSlider_valueChanged(int value)
{
	play->setVolume(value);
	QString valueStr = QString("%1").arg(value);
	volumSlider->setToolTip(QStringLiteral("����:") + valueStr);
	volumBox->setToolTip(QStringLiteral("����:") + valueStr);
	volumBtn->setToolTip(QStringLiteral("����:") + valueStr);
}
/*
void MyMPlayer::on_slider_sliderMoved(int position)
{
play->stop();
timer->stop();
//position = slider->value();
play->setPosition(slider->value());
timer->start();
play->play();

if (pauseBtn->toolTip() == tr("����"))
{
pauseBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/pause_hover1.png);}"
"QPushButton:hover{border-image: url(:/new/prefix1/Resources/pause_hover.png);}"
"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/pause_press.png);}"
"QPushButton:focus{padding:-1;}");
pauseBtn->setToolTip("��ͣ");
}

}
*/

void MyPlayer::on_pushButton_clicked()
{

	if (tableWidget->isHidden())
		tableWidget->show();
	else
		tableWidget->hide();
}
void MyPlayer::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		dragPos = event->globalPos() - frameGeometry().topLeft();
		event->accept();
	}
}

void MyPlayer::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons()&Qt::LeftButton)
	{
		move(event->globalPos() - dragPos);
		event->accept();
	}
}

void MyPlayer::on_pushButton_4_clicked()
{
	exit(0);
}

void MyPlayer::on_pushButton_5_clicked()
{
	myTrayIcon();//����
	//this->showMinimized();
	this->hide();
}

void MyPlayer::on_pushButton_3_clicked()
{

	QString initialName = QDir::homePath();
	QStringList pathList = QFileDialog::getOpenFileNames(this, QStringLiteral("ѡ���ļ�"), initialName, QStringLiteral("*.mp3 *.wma *.m4a *.ogg *.aac *.ape"));
	for (int i = 0; i<pathList.size(); ++i) {
		QString path = QDir::toNativeSeparators(pathList.at(i));
		if (!path.isEmpty()) {
			playList->addMedia(QUrl::fromLocalFile(path));
			QString fileName = path.split("\\").last();
			int rownum = tableWidget->rowCount();
			tableWidget->insertRow(rownum);
			tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
			tableWidget->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
			tableWidget->setItem(rownum, 2, new QTableWidgetItem(QDir::toNativeSeparators(pathList.at(i))));
		}
	}
}

void MyPlayer::on_modelBtn_clicked()
{
	if (modelBtn->toolTip() == tr("˳�򲥷�"))
	{
		playList->setPlaybackMode(QMediaPlaylist::Random);//���
		modelBtn->setToolTip("�������");
		modelBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/suiji.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/suiji.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/suiji.png);}"
			"QPushButton:focus{padding:-1;}");
	}
	else if (modelBtn->toolTip() == tr("�������"))
	{
		playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//����
		modelBtn->setToolTip("����ѭ��");
		modelBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/xunhuan.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/xunhuan.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/xunhuan.png);}"
			"QPushButton:focus{padding:-1;}");
	}
	else
	{
		playList->setPlaybackMode(QMediaPlaylist::Loop); //˳��
		modelBtn->setToolTip("˳�򲥷�");
		modelBtn->setStyleSheet("QPushButton:!hover{border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);}"
			"QPushButton:hover{border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);}"
			"QPushButton:pressed{border-image: url(:/new/prefix1/Resources/mymusic/shunxu.png);}"
			"QPushButton:focus{padding:-1;}");
	}
}


void MyPlayer::on_login_clicked()
{

	dislikefile();
}

void MyPlayer::on_timeClock_clicked()
{
	if (timeEdit->isHidden())
		timeEdit->show();
	else
		timeEdit->hide();
	if (timeLabel->isHidden())
		timeLabel->show();
	else
		timeLabel->hide();
}

//����
void MyPlayer::myTrayIcon()
{

	QIcon icon = QIcon(":/new/prefix1/Resources/mymusic/tuopan.png");
	trayIcon->setIcon(icon);
	trayIcon->setToolTip(QStringLiteral("���ص�����"));
	trayIcon->show();
	//����������ʾ
	trayIcon->showMessage(QStringLiteral("���Ķ���,�ҵ�Player"), QStringLiteral("���ص�����"), QSystemTrayIcon::Information, 5000);
	//��ӵ�/˫�������Ӧ
	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
		this, SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));
	//��Ϊ
	minimizeAction = new QAction(QStringLiteral("��С�� (&I)"), this);
	connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
	before = new QAction(QStringLiteral("��һ�� (&B)"), this);
	connect(before, SIGNAL(triggered()), this, SLOT(on_backBtn_clicked()));
	pause = new QAction(QStringLiteral("����/��ͣ (&P)"), this);
	connect(pause, SIGNAL(triggered()), this, SLOT(pauseBtnClicked()));
	next = new QAction(QStringLiteral("��һ�� (&N)"), this);
	connect(next, SIGNAL(triggered()), this, SLOT(on_nextone_clicked()));
	restoreAction = new QAction(QStringLiteral("��ԭ (&R)"), this);
	connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
	aboutus = new QAction(QStringLiteral("��������"), this);
	connect(aboutus, SIGNAL(triggered()), this, SLOT(aboutUs()));
	quitAction = new QAction(QStringLiteral("�˳� (&Q)"), this);
	connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

	//�����Ҽ������˵�
	trayIconMenu = new QMenu(this);
	trayIconMenu->addAction(minimizeAction);

	trayIconMenu->addAction(before);
	trayIconMenu->addAction(pause);
	trayIconMenu->addAction(next);
	trayIconMenu->addAction(restoreAction);
	trayIconMenu->addSeparator();
	trayIconMenu->addAction(aboutus);
	trayIconMenu->addAction(quitAction);
	trayIcon->setContextMenu(trayIconMenu);


}

//�б��Ҽ�ѡ��
void MyPlayer::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu menu;
	menu.addAction(QStringLiteral("���沥���б�"), this, SLOT(likefile()));
	menu.addAction(QStringLiteral("ɾ������"), this, SLOT(deleteSelectedMusic()));
	menu.addAction(QStringLiteral("����б�"), this, SLOT(clearPlaylist()));
	menu.exec(event->globalPos());
}

void MyPlayer::deleteSelectedMusic()
{
	QTableWidgetItem * item = tableWidget->currentItem();
	if (item == Q_NULLPTR)
		return;
	playList->removeMedia(tableWidget->currentRow());
	tableWidget->removeRow(item->row());
	//emit isModified();
	//emit playlistReduced();
}

void MyPlayer::clearPlaylist()
{
	while (tableWidget->rowCount()){
		tableWidget->removeRow(0);
		playList->removeMedia(0);
	}
	//emit isModified();
	//emit playlistReduced();
}

//�����Ӧ
void MyPlayer::trayiconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:
		//��������ͼ��
	case QSystemTrayIcon::DoubleClick:
		//˫������ͼ��
		this->showNormal();
		this->raise();
		break;
	default:
		break;
	}
}

void MyPlayer::aboutUs()
{

	QMessageBox::information(this, QStringLiteral("��������"), QStringLiteral("��Ȩ���з�:\t\n\t������@XingHeng\n\tGUOwenrui@XingHeng"));
}






void MyPlayer::on_pushClean_clicked()
{
	//this->hide();
	emit open_clean();
	emit close_self();

	//sleep(50);
	//this->hide();

}

void MyPlayer::on_pushSetm_clicked()
{
	//this->hide();
	emit open_setmdole();
	emit close_self();
	//sleep(50);
	//this->hide();

}

void MyPlayer::on_pushProcess_clicked()
{
	//this->hide();
	emit open_process();
	emit close_self();
	//sleep(50);
	//this->hide();

}

void MyPlayer::on_pushSetp_clicked()
{

	emit open_setparameter();
	emit close_self();
	//sleep(50);
	//this->hide();

}

//setWindowFlags( Qt::WindowStaysOnTopHint);
//setWindowFlags(Qt::WindowModal);

void MyPlayer::show_me(){

	this->show();
	//this->setWindowState(Qt::WindowActive);

	//emit close_self();
}
