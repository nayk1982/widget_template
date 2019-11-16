#===============================================================================
#
# Widget Template Project
#
#===============================================================================
QT      += core gui widgets

CONFIG  += c++14

DEFINES += QT_DEPRECATED_WARNINGS

# Sources and Headers ==========================================================
INCLUDEPATH += \
    $${PWD}/include \
    $${PWD}/../../_nayk/include

SOURCES += \
    $${PWD}/../../_nayk/sources/app_core.cpp \
    $${PWD}/../../_nayk/sources/gui_app_core.cpp \
    $${PWD}/../../_nayk/sources/gui_utils.cpp \
    $${PWD}/../../_nayk/sources/log.cpp \
    $${PWD}/../../_nayk/sources/dialog_log.cpp \
    $${PWD}/../../_nayk/sources/convert.cpp \
    $${PWD}/../../_nayk/sources/file_sys.cpp \
    $${PWD}/../../_nayk/sources/system_utils.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    $${PWD}/../../_nayk/include/app_core.h \
    $${PWD}/../../_nayk/include/gui_app_core.h \
    $${PWD}/../../_nayk/include/gui_utils.h \
    $${PWD}/../../_nayk/include/log.h \
    $${PWD}/../../_nayk/include/dialog_log.h \
    $${PWD}/../../_nayk/include/images_const.h \
    $${PWD}/../../_nayk/include/convert.h \
    $${PWD}/../../_nayk/include/file_sys.h \
    $${PWD}/../../_nayk/include/system_utils.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Resources files ==============================================================
RESOURCES += \
    main.qrc \
    $${PWD}/../../_nayk/resources/common.qrc

win32:RC_FILE = main.rc

# Output dir ===================================================================
CONFIG(release, debug|release) {
    win32: DESTDIR = $${PWD}/../_distrib/win_$${QMAKE_HOST.arch}
    else: unix:!android: DESTDIR  = $${PWD}/../_distrib/linux_$${QMAKE_HOST.arch}
}

# Version and Build date =======================================================
win32: BUILD_DATE = '$(shell echo %DATE:~6,4%-%DATE:~3,2%-%DATE:~0,2%)'
else:  BUILD_DATE = '$(shell date +%Y-%m-%d)'
VERSION  = 1.0
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += APP_BUILD_DATE=\\\"$$BUILD_DATE\\\"

# translations =================================================================
#TRANSLATIONS += $${PWD}/translations/main_ru.ts
#main_tr.commands = lrelease $${PWD}/translations/main_ru.ts -qm $${PWD}/translations/main_ru.qm
#PRE_TARGETDEPS += main_tr
#QMAKE_EXTRA_TARGETS += main_tr
