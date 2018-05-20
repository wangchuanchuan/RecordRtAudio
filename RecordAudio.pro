#-------------------------------------------------
#
# Project created by QtCreator 2018-05-19T15:42:23
#
#-------------------------------------------------

QT       += core widgets gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RtAudio
TEMPLATE = app

LIBS += -lole32 \
    -lwinmm \
    -ldsound

DEFINES += __WINDOWS_DS__


HEADERS += \
    Thread.h \
    rtaudio/RtAudio.h \
    Recording.h

SOURCES += \
    Thread.cpp \
    rtaudio/RtAudio.cpp \
    Recording.cpp \
    main.cpp

FORMS += \
    Recording.ui
