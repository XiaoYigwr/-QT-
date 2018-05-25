#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T14:08:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widgetTowidget4
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    check.cpp \
    clean.cpp \
    process.cpp \
    setmodel.cpp \
    setparameter.cpp \
    my_thread.cpp

HEADERS  += widget.h \
    check.h \
    clean.h \
    process.h \
    setmodel.h \
    setparameter.h \
    my_thread.h

FORMS    += widget.ui \
    check.ui \
    clean.ui \
    process.ui \
    setmodel.ui \
    setparameter.ui
