#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T21:58:42
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sist_matriculas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adm_window.cpp \
    director_window.cpp \
    dbf.cpp \
    data_base.cpp

HEADERS  += mainwindow.h \
    adm_window.h \
    director_window.h \
    dbf.h \
    data_base.h \
    libraries.h

FORMS    += mainwindow.ui \
    adm_window.ui \
    director_window.ui
