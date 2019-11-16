#include <QApplication>
#include <QFile>
#include <QSplashScreen>
#include <QPixmap>
#include "GuiAppCore"
#include "ImagesConst"
#include "mainwindow.h"
//==================================================================================================
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(!gui_app_core::initializeApplication( "WidgetTemplate",
                                             "WidgetTemplate",
                                             "Organization",
                                             "OrgDomain"
                                             )) {
        return 0;
    }

    QSplashScreen *splash {nullptr};
    if(QFile::exists(nayk::imageMainSplash)) {
        splash = new QSplashScreen( QPixmap(nayk::imageMainSplash) );
        splash->show();
    }


    MainWindow w;
    w.show();

    if(splash) {
        splash->hide();
        delete splash;
    }

    return a.exec();
}
//==================================================================================================
