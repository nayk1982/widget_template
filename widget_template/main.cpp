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
    if(!nayk::GuiAppCore::initApplication( "WidgetTemplate",
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
