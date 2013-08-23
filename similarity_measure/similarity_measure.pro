#-------------------------------------------------
#
# Project created by QtCreator 2013-08-19T13:27:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = similarity_measure
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    res/similarity_measure.cpp \
    res/similarity_measure_map.cpp \
    stemmer/porter_stemmer.cpp \
    res/db_connector.cpp \
    db_similarity.cpp

HEADERS  += mainwindow.h \
    res/similarity_measure.h \
    res/similarity_measure_map.h \
    stemmer/Stemmer.h \
    stemmer/porter_stemmer.h \
    res/db_connector.h \
    db_similarity.h

FORMS    += mainwindow.ui

LIBS += D:/mariadb_client-1.0.0-win32/lib/libmariadb.lib

INCLUDEPATH += D:\mariadb_client-1.0.0-win32\mariadbclient\include
