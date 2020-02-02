#===============================================================================
#
# Widget Template Project
#
#===============================================================================

QT += core gui widgets

include( $${PWD}/../../_nayk/nayk.pri )

# Includes =====================================================================

INCLUDEPATH *= \
    $${PWD}/include

# Sources and Headers ==========================================================

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
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
