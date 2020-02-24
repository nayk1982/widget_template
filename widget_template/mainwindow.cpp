#include "nayk/GuiUtils"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogsettings.h"
//==============================================================================

using namespace nayk;
using namespace gui_utils;

//==============================================================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    applySettings();
    moveToCenterScreen(this);

    ui->actionToolBar->setChecked( m_settings.readParameter("toolbar", true).toBool() );
    ui->toolBar->setVisible( ui->actionToolBar->isChecked() );
    connect(ui->toolBar, &QToolBar::visibilityChanged,
            this, &MainWindow::on_toolBarVisibilityChanged);

    gui_utils::updateApplicationStyle();
    emit toLog(tr("Start program"), Log::LogInfo);
}
//==============================================================================
MainWindow::~MainWindow()
{
    emit toLog(tr("Finish program"), Log::LogInfo);

    if(m_log) {
        delete m_log;
    }

    if(m_dialogLog) {
        delete m_dialogLog;
    }

    delete ui;
}
//==============================================================================
void MainWindow::applySettings()
{
    if(m_settings.logSave() || m_settings.debug()) {

        if(!m_log) {
            m_log = new Log(this);
            connect(this, &MainWindow::toLog, m_log, &Log::saveToLog);
        }

        if(m_settings.debug() && !m_dialogLog) {
            m_dialogLog = new DialogLog(this);
            connect(this, &MainWindow::toLog, m_dialogLog, &DialogLog::saveToLog, Qt::QueuedConnection);
        }
    }
    else {

        if(m_log) {
            delete m_log;
            m_log = nullptr;
        }

        if(m_dialogLog) {
            delete m_dialogLog;
            m_dialogLog = nullptr;
        }
    }

    if(m_log) {
        m_log->setDebugSave(m_settings.debug());
        m_log->deleteOldLogFiles("*.log", m_settings.logCount());
    }

    ui->actionLog->setVisible(m_dialogLog);
}
//==============================================================================
void MainWindow::closeEvent(QCloseEvent *event)
{
    if ( messageConfirm( tr("Quit the program?")) ) {

        event->accept();
    }
    else {
        event->ignore();
    }
}
//==============================================================================
void MainWindow::on_actionExit_triggered()
{
    close();
}
//==============================================================================
void MainWindow::on_actionToolBar_triggered(bool checked)
{
    m_settings.writeParameter("toolbar", checked);
    ui->toolBar->setVisible(checked);
}
//==============================================================================
void MainWindow::on_actionSettings_triggered()
{
    DialogSettings dlg(&m_settings, this);
    connect(&dlg, &DialogSettings::toLog, this, &MainWindow::toLog);

    if(dlg.exec() == QDialog::Accepted) {

        applySettings();
    }
}
//==============================================================================
void MainWindow::on_actionAbout_triggered()
{
    showAboutDialog( qApp->applicationDisplayName(),
                     developerStr,
                     descriptionStr );
}
//==============================================================================
void MainWindow::on_toolBarVisibilityChanged(bool visibility)
{
    if(!this->isVisible()) return;
    ui->actionToolBar->setChecked(visibility);
}
//==============================================================================
