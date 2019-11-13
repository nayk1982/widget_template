#include "GuiUtils"
#include "mainwindow.h"
#include "ui_mainwindow.h"
//==================================================================================================
using namespace nayk;

const QString developerStr   = QObject::tr("Евгений Тетерин");
const QString descriptionStr = QObject::tr("Описание приложения");

//==================================================================================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialogLog = new DialogLog(this);
    connect(this, &MainWindow::toLog, dialogLog, &DialogLog::saveToLog);

    log = new Log(this);
    connect(this, &MainWindow::toLog, log, &Log::saveToLog);

    GuiUtils::moveToCenterScreen(this);
}
//==================================================================================================
MainWindow::~MainWindow()
{
    if(log) {
        delete log;
    }

    if(dialogLog) {
        delete dialogLog;
    }

    delete ui;
}
//==================================================================================================
void MainWindow::closeEvent(QCloseEvent *event)
{
    if ( GuiUtils::messageConfirm( this, tr("Завершить работу с программой?")) ) {

        event->accept();
    }
    else {
        event->ignore();
    }
}
//==================================================================================================
void MainWindow::on_actionExit_triggered()
{
    close();
}
//==================================================================================================
void MainWindow::on_actionToolBar_triggered(bool checked)
{
    ui->toolBar->setVisible(checked);
}
//==================================================================================================
void MainWindow::on_actionSettings_triggered()
{

}
//==================================================================================================
void MainWindow::on_actionAbout_triggered()
{
    GuiUtils::showAboutDialog( developerStr, descriptionStr );
}
//==================================================================================================
