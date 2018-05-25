#include "widget.h"
#include "myplayer.h"
#include <QApplication>
#include <QTextCodec>
#include <QPixmap>
#include <QSplashScreen>
#include<qbitmap>

int main(int argc, char *argv[])
{
	void sleep(unsigned int msec);
    QApplication app(argc, argv);

    ///QTextCodec::setCodecForTr( QTextCodec::codecForName("utf8") );

    Widget w;

	/*
	QPixmap pixMap(":/new/prefix1/Resources/skin/1.jpg");
	QSplashScreen splash(pixMap);
	splash.show();
	sleep(1000);
	app.processEvents();

	splash.finish(&w);*/
	w.show();

    return app.exec();
}

void sleep(unsigned int msec)

{

	QTime dieTime = QTime::currentTime().addMSecs(msec);

	while (QTime::currentTime() < dieTime)

		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}