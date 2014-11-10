#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T16:33:38
#
#-------------------------------------------------

QT       += core gui

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManagerOS
TEMPLATE = app

INCLUDEPATH += ./Login \
            += ./ManageControl \
            += ./EntryPersonal \
            += ./QueryModify   \
            += ./Service/include \


SOURCES += main.cpp\
        mainwindow.cpp \
    Login/Login.cpp \
    ManageControl/ManageControl.cpp \
    EntryPersonal/EntryPersonal.cpp \
    Service/PersonalSqlService.cpp \
    QueryModify/QueryModify.cpp

HEADERS  += mainwindow.h \
    Login/Login.h \
    DataShare.h \
    ManageControl/ManageControl.h \
    EntryPersonal/EntryPersonal.h \
    Service/include/PersonalSqlService.h \
    QueryModify/QueryModify.h

FORMS    += mainwindow.ui \
    Login/Login.ui \
    ManageControl/ManageControl.ui \
    EntryPersonal/EntryPersonal.ui \
    QueryModify/QueryModify.ui
