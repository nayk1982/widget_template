#include "GuiUtils"
#include "dialogsettings.h"
#include "ui_dialogsettings.h"
//==============================================================================
DialogSettings::DialogSettings(Settings *settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSettings),
    m_settings(settings)
{
    ui->setupUi(this);
    ui->checkBoxLogSave->setChecked(m_settings->logSave());
    ui->spinBoxLogCount->setValue(m_settings->logCount());
}
//==============================================================================
DialogSettings::~DialogSettings()
{
    delete ui;
}
//==============================================================================
void DialogSettings::on_buttonBox_accepted()
{
    m_settings->setLogSave(ui->checkBoxLogSave->isChecked());
    m_settings->setLogCount(ui->spinBoxLogCount->value());

    if(!m_settings->saveSettings()) {
        gui_utils::messageError(tr("Failed to save settings: %1")
                                .arg(m_settings->lastError()));
    }
}
//==============================================================================
