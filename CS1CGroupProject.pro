#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T17:14:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CS1CGroupProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        canvas.cpp \
	contact.cpp \
	drawwidg.cpp \
        login.cpp \
        main.cpp \
        mainwindow.cpp \
        rectangle.cpp \
        shapeparser.cpp \
        shapes.cpp \
        text.cpp

HEADERS += \
        canvas.h \
	contact.h \
	drawwidg.h \
        login.h \
        mainwindow.h \
        rectangle.h \
        shapeparser.h \
	shapes.h \
        text.h \
        vector.h

FORMS += \
        contact.ui \
        login.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	shapes.txt
