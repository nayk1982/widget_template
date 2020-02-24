#===============================================================================
#
# Widget Template Project
#
#===============================================================================

QT += core gui widgets

VERSION = 1.0

include( $${PWD}/../../../_nayk/nayk_common.pri )

# Includes =====================================================================

INCLUDEPATH *= \
    $${PWD}/include

# Sources and Headers ==========================================================

SOURCES += \
    src/settings.cpp \
    dialogsettings.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    include/settings.h \
    dialogsettings.h \
    mainwindow.h

FORMS += \
    dialogsettings.ui \
    mainwindow.ui

# Resources files ==============================================================

RESOURCES += \
    main.qrc \
    $${NAYK_DIR}/resources/icons.qrc \

win32:RC_FILE = main.rc

# translations =================================================================

TRANSLATIONS += \
    $${PWD}/translations/main_ru.ts

main_tr.commands = lrelease $${PWD}/translations/main_ru.ts -qm $${PWD}/translations/main_ru.qm

PRE_TARGETDEPS += \
    main_tr

QMAKE_EXTRA_TARGETS += \
    main_tr

# Libs =========================================================================

INCLUDEPATH *= \
    $${COMMON_LIBS_DIR}/include

win32 {
    NAYK_LIB_VER = 1
}

LIBS *= \
    -L$${COMMON_LIBS_DIR} \
    -lnayk_core$${NAYK_LIB_VER} \
    -lnayk_widgets$${NAYK_LIB_VER} \
