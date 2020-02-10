#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>
#include "Settings"
#include "Log"
//==============================================================================
namespace Ui {
class DialogSettings;
}
//==============================================================================
class DialogSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSettings(Settings *settings, QWidget *parent = nullptr);
    ~DialogSettings();

signals:
    void toLog(const QString &text, nayk::Log::LogType logType = nayk::Log::LogInfo);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogSettings *ui;
    Settings *m_settings {nullptr};
};
//==============================================================================
#endif // DIALOGSETTINGS_H
