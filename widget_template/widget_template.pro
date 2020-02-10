#===============================================================================
#
# Widget Template Project
#
#===============================================================================

QT += core gui widgets

VERSION = 1.0

include( $${PWD}/../../_nayk/nayk.pri )

# Includes =====================================================================

INCLUDEPATH *= \
    $${PWD}/include

# Sources and Headers ==========================================================

SOURCES += \
    dialogsettings.cpp \
    src/settings.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialogsettings.h \
    include/settings.h \
    mainwindow.h

FORMS += \
    dialogsettings.ui \
    mainwindow.ui

# Resources files ==============================================================

RESOURCES += \
    main.qrc

win32:RC_FILE = main.rc

# translations =================================================================

#TRANSLATIONS += \
#    $${PWD}/translations/main_ru.ts
#
#main_tr.commands = lrelease $${PWD}/translations/main_ru.ts -qm $${PWD}/translations/main_ru.qm
#
#PRE_TARGETDEPS += \
#    main_tr
#
#QMAKE_EXTRA_TARGETS += \
#    main_tr
