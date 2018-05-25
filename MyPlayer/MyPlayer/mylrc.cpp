#include "mylrc.h"
#include <QTimer>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QMenu>
#include <QPainter>

MyLrc::MyLrc(QWidget *parent) :
QLabel(parent)
{

	setWindowFlags(Qt::FramelessWindowHint);//�����ޱ߿�
	setAttribute(Qt::WA_TranslucentBackground);//������ȫ͸��
	setText(QStringLiteral("My Music Player"));
	setWindowTitle("LRC DISPLAY");
	setWindowIcon(QIcon(":/new/prefix1/Resources/icon.png"));
	// �̶���ʾ�����С
	setMaximumSize(800, 60);
	setMinimumSize(800, 60);
	setWindowOpacity(1);
	setMouseTracking(true);


	lineargradient.setStart(0, 10);
	lineargradient.setFinalStop(0, 40);
	lineargradient.setColorAt(0.1, QColor(14, 179, 255));
	lineargradient.setColorAt(0.5, QColor(114, 232, 255));
	lineargradient.setColorAt(0.9, QColor(14, 179, 255));

	masklineargradient.setStart(0, 10);
	masklineargradient.setFinalStop(0, 40);
	masklineargradient.setColorAt(0.1, QColor(222, 54, 4));
	masklineargradient.setColorAt(0.5, QColor(255, 72, 16));
	masklineargradient.setColorAt(0.9, QColor(222, 54, 4));


	font.setFamily("Times New Roman");
	font.setBold(true);
	font.setPointSize(30);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
	lrc_mask_width = 0;
	lrc_mask_width_interval = 0;
}

void MyLrc::start_lrc_mask(qint64 intervaltime)
{
	qreal count = intervaltime / 30;// ÿ��30�������һ�����ֵĿ��
	// ��ȡ����ÿ����Ҫ���ӵĿ�ȣ������800�ǲ����Ĺ̶����
	lrc_mask_width_interval = 800 / count;
	lrc_mask_width = 0;
	timer->start(30);
}

void MyLrc::stop_lrc_mask()
{
	timer->stop();
	lrc_mask_width = 0;
	update();
}

//��������:�ػ洰�ڸ��
void MyLrc::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setFont(font);
	painter.setPen(QColor(0, 0, 0, 200));
	painter.drawText(1, 1, 800, 60, Qt::AlignLeft, text());

	painter.setPen(QPen(lineargradient, 0));
	painter.drawText(0, 0, 800, 60, Qt::AlignLeft, text());

	painter.setPen(QPen(masklineargradient, 0));
	painter.drawText(0, 0, lrc_mask_width, 60, Qt::AlignLeft, text());
}
void MyLrc::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
		offset = event->globalPos() - frameGeometry().topLeft();
}
void MyLrc::mouseMoveEvent(QMouseEvent *event)
{
	//�ƶ���굽�����ʱ������ʾ����
	if (event->buttons() & Qt::LeftButton) {
		setCursor(Qt::PointingHandCursor);
		//ʵ���ƶ�����
		move(event->globalPos() - offset);
	}
}
void MyLrc::contextMenuEvent(QContextMenuEvent *event)
{
	QMenu menu;
	menu.addAction(QStringLiteral("����"), this, SLOT(hide()));
	menu.exec(event->globalPos());//globalPos()Ϊ��ǰ����λ������
}
void MyLrc::timeout()
{
	lrc_mask_width += lrc_mask_width_interval;
	update();//����widget�����ǲ��������ػ棬���ǰ���һ��Paint�¼�����������ѭ��ʱ��ϵͳ���ػ�
}




