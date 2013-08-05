#-------------------------------------------------
#
# Project created by QtCreator 2013-08-03T10:46:00
#
#-------------------------------------------------

QT       += core gui \
            sql

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = word_similarity
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    porter_stemmer.cpp

HEADERS  += mainwindow.h \
    porter_stemmer.h

FORMS    += mainwindow.ui
