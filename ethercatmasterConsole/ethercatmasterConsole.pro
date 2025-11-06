#QT -= gui
QT       += core sql gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 console
CONFIG -= app_bundle

#为了自动填补方便
#QT       += core gui network
#QT       += testlib
#QT       += sql
#QT += multimedia multimediawidgets
#QT       += serialbus serialport
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
#CONFIG += c++11

######
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/../ethercat-master/include
#LIBS += $$PWD../ethercat-master/lib/.libs/*.o
LIBS += $$files($$PWD/../ethercat-master/lib/.libs/*.o)

SOURCES += \
        ../cKVMCoreWid/source/carguments/cBaseVar.cpp \
        ../cKVMCoreWid/source/carguments/cvarzeromq.cpp \
        ../cKVMCoreWid/source/taskmanager/taskmanger.cpp \
        etcHeader/etcheader.cpp \
        etcHeader/ethercatmaster-autoconfig.cpp \
        etcHeader/ethercatmaster-axis.cpp \
        etcHeader/ethercatmaster-pthread.cpp \
        etcHeader/ethercatmaster-udp.cpp \
        etcHeader/ethercatmaster.cpp \
        etcHeader/jmc_axis_cmd.cpp \
        etcHeader/jmc_bu5_tc.cpp \
        etcHeader/jmc_camin.cpp \
        etcHeader/jmc_home.cpp \
        etcHeader/jmc_jog.cpp \
        etcHeader/jmc_moveabs.cpp \
        etcHeader/jmc_movereal.cpp \
        etcHeader/jmc_movevel.cpp \
        etcHeader/jmc_power.cpp \
        etcHeader/jmc_reset.cpp \
        etcHeader/jmc_setpos.cpp \
        etcHeader/jmc_stop.cpp \
        etcHeader/jmc_wtmc_tc.cpp \
        etcHeader/null.cpp \
        etcHeader/velo_planing.cpp \
        main.cpp \
        velplan/s7_vel_plan.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


LIBS +=-lpthread
LIBS +=-lrt
LIBS +=-lzmq
HEADERS += \
    ../cKVMCoreWid/include/carguments/cBaseVar.h \
    ../cKVMCoreWid/include/carguments/cvarzeromq.h \
    ../cKVMCoreWid/include/taskmanager/taskmanger.h \
    etcHeader/etcheader.h \
    etcHeader/ethercatmaster.h \
    etcHeader/jmc_axis_cmd.h \
    velplan/s7_vel_plan.h
