QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += link_pkgconfig
PKGCONFIG += cBaseVarsV2

INCLUDEPATH += $$PWD/../ethercat-master/include
#LIBS += $$PWD../ethercat-master/lib/.libs/*.o
LIBS += $$files($$PWD/../ethercat-master/lib/.libs/*.o)

SOURCES += \
    ../ethercatmasterConsole/etcHeader/etcheader.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_axis_cmd.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_bu5_tc.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_home.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_jog.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_moveabs.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_movereal.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_movevel.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_power.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_reset.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_setpos.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_stop.cpp \
    ../ethercatmasterConsole/etcHeader/jmc_wtmc_tc.cpp \
    ../ethercatmasterConsole/etcHeader/null.cpp \
    ../ethercatmasterConsole/etcHeader/velo_planing.cpp \
    ../ethercatmasterConsole/velplan/s7_vel_plan.cpp \
    main.cpp \
    ctoolswid.cpp \
    source/csoftmotion/caxispage.cpp \
    source/csoftmotion/cethercatpage.cpp \
    source/csoftmotion/cslavepage.cpp \
    source/csoftmotion/jmchomewidget.cpp \
    source/csoftmotion/jmcjogwidget.cpp \
    source/csoftmotion/jmcmoveabswdiget.cpp \
    source/csoftmotion/jmcmovevelwidget.cpp \
    source/csoftmotion/jmcpowerwidget.cpp \
    source/csoftmotion/jmcresetwidget.cpp \
    source/csoftmotion/jmcsetposwidget.cpp \
    source/csoftmotion/jmcstopwidget.cpp \
    source/csoftmotion/jmcwtmtccwidget.cpp \
    source/cwidget/slaveConfWid/axis_setting_wid.cpp \
    source/cwidget/slaveConfWid/ethercatwid.cpp \
    source/cwidget/slaveConfWid/slave_assign_wid.cpp \
    source/cwidget/slaveConfWid/slave_conf_dg.cpp \
    source/cwidget/slaveConfWid/slave_index_wid.cpp \
    source/cwidget/slaveConfWid/slave_pdo_wid.cpp \
    source/cwidget/slaveConfWid/slave_startup_wid.cpp \

HEADERS += \
    ../ethercatmasterConsole/etcHeader/etcheader.h \
    ../ethercatmasterConsole/etcHeader/jmc_axis_cmd.h \
    ../ethercatmasterConsole/velplan/s7_vel_plan.h \
    ctoolswid.h \
    include/csoftmotion/caxispage.h \
    include/csoftmotion/cethercatpage.h \
    include/csoftmotion/cslavepage.h \
    include/csoftmotion/jmchomewidget.h \
    include/csoftmotion/jmcjogwidget.h \
    include/csoftmotion/jmcmoveabswdiget.h \
    include/csoftmotion/jmcmovevelwidget.h \
    include/csoftmotion/jmcpowerwidget.h \
    include/csoftmotion/jmcresetwidget.h \
    include/csoftmotion/jmcsetposwidget.h \
    include/csoftmotion/jmcstopwidget.h \
    include/csoftmotion/jmcwtmtccwidget.h \
    include/cwidget/slaveConfWid/axis_setting_wid.h \
    include/cwidget/slaveConfWid/ethercatwid.h \
    include/cwidget/slaveConfWid/qt59to514.h \
    include/cwidget/slaveConfWid/slave_assign_wid.h \
    include/cwidget/slaveConfWid/slave_conf_dg.h \
    include/cwidget/slaveConfWid/slave_index_wid.h \
    include/cwidget/slaveConfWid/slave_pdo_wid.h \
    include/cwidget/slaveConfWid/slave_startup_wid.h \

FORMS += \
    ctoolswid.ui \
    include/csoftmotion/caxispage.ui \
    include/csoftmotion/cethercatpage.ui \
    include/csoftmotion/cslavepage.ui \
    include/csoftmotion/jmchomewidget.ui \
    include/csoftmotion/jmcjogwidget.ui \
    include/csoftmotion/jmcmoveabswdiget.ui \
    include/csoftmotion/jmcmovevelwidget.ui \
    include/csoftmotion/jmcpowerwidget.ui \
    include/csoftmotion/jmcresetwidget.ui \
    include/csoftmotion/jmcsetposwidget.ui \
    include/csoftmotion/jmcstopwidget.ui \
    include/csoftmotion/jmcwtmtccwidget.ui \
    include/cwidget/slaveConfWid/axis_setting_wid.ui \
    include/cwidget/slaveConfWid/ethercatwid.ui \
    include/cwidget/slaveConfWid/slave_assign_wid.ui \
    include/cwidget/slaveConfWid/slave_conf_dg.ui \
    include/cwidget/slaveConfWid/slave_index_wid.ui \
    include/cwidget/slaveConfWid/slave_pdo_wid.ui \
    include/cwidget/slaveConfWid/slave_startup_wid.ui


LIBS +=-lpthread
LIBS +=-lrt
LIBS +=-lzmq
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../cBaseVarsV2/source/cwidget/create_shared_memory
