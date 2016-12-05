#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T21:28:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EyeSecurity
TEMPLATE = app


SOURCES += main.cpp\
        eye_sec_user.cpp \
    user_input_error.cpp \
    eye_sec_admin.cpp

HEADERS  += eye_sec_user.h \
    user_input_error.h \
    eye_sec_admin.h \
    eyesecurity.h

FORMS    += \
    eye_sec_user.ui \
    user_input_error.ui \
    eye_sec_admin.ui

RESOURCES += \
    resources.qrc
