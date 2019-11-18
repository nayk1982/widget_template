#===============================================================================
#
# Widget Template Project
#
#===============================================================================

include( $${PWD}/../../_nayk/widget_app.pri )

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

# Output dir ===================================================================
CONFIG(release, debug|release) {
    win32: DESTDIR = $${PWD}/../_distrib/win_$${QMAKE_HOST.arch}
    else: unix:!android: DESTDIR  = $${PWD}/../_distrib/linux_$${QMAKE_HOST.arch}
}

# translations =================================================================
#TRANSLATIONS += $${PWD}/translations/main_ru.ts
#main_tr.commands = lrelease $${PWD}/translations/main_ru.ts -qm $${PWD}/translations/main_ru.qm
#PRE_TARGETDEPS += main_tr
#QMAKE_EXTRA_TARGETS += main_tr
