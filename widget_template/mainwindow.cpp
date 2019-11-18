#include "GuiUtils"
#include "mainwindow.h"
#include "ui_mainwindow.h"
//==================================================================================================
using namespace nayk;
using namespace gui_utils;

const QString developerStr   = QObject::tr("Evgeny Teterin");
const QString descriptionStr = QObject::tr("Description");

//==================================================================================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialogLog = new DialogLog(this);
    connect(this, &MainWindow::toLog, dialogLog, &DialogLog::saveToLog, Qt::QueuedConnection);

    log = new Log(this);
    connect(this, &MainWindow::toLog, log, &Log::saveToLog, Qt::QueuedConnection);

    moveToCenterScreen(this);
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
    if ( messageConfirm( this, tr("Close application?")) ) {

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
    showAboutDialog( developerStr, descriptionStr );
}
//==================================================================================================
