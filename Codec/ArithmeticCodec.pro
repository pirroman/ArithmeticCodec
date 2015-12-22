#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T09:56:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArithmeticCodec
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        window_qcodec.cpp \
    encoding.cpp \
    decoding.cpp

HEADERS  += window_qcodec.h \
    cut_low_hight.h

FORMS    += window_qcodec.ui
