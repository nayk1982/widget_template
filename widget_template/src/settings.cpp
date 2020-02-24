#include "nayk/AppCore"
#include "nayk/FileSys"
#include "settings.h"

//==============================================================================

using namespace nayk;
using namespace file_sys;

//==============================================================================
Settings::Settings(QObject *parent) : QObject(parent)
{
    m_debug = app_core::parameterExists("debug")
                || file_sys::fileExists(applicationPath() + "debug") ;
    readSettings();
}
//==============================================================================
bool Settings::saveSettings()
{
    emit startWrite();
    emit toLog(tr("Save settings to file '%1'")
               .arg(file_Config), Log::LogInfo);

    QSettings ini(profilePath() + file_Config, QSettings::IniFormat);
    ini.setIniCodec("UTF-8");
    ini.setValue("log/save", m_logSave);
    ini.setValue("log/count", m_logCount);

    ini.sync();
    emit finishWrite();
    return checkIniStatus(ini);
}
//==============================================================================
QString Settings::applicationPath() const
{
    return app_core::applicationRootPath();
}
//==============================================================================
QString Settings::profilePath() const
{
    return app_core::applicationProfilePath();
}
//==============================================================================
QString Settings::lastError() const
{
    return m_lastError;
}
//==============================================================================
bool Settings::writeParameter(const QString &name, QVariant value) const
{
    QSettings ini(profilePath() + file_Params, QSettings::IniFormat);
    ini.setIniCodec("UTF-8");
    ini.setValue("save/" + name, value);
    ini.sync();
    return (ini.status() == QSettings::NoError);
}
//==============================================================================
QVariant Settings::readParameter(const QString &name, QVariant defaultValue) const
{
    QSettings ini(profilePath() + file_Params, QSettings::IniFormat);
    ini.setIniCodec("UTF-8");
    return ini.value("save/" + name, defaultValue);
}
//==============================================================================
bool Settings::debug() const
{
    return m_debug;
}
//==============================================================================
bool Settings::logSave() const
{
    return m_logSave;
}
//==============================================================================
void Settings::setLogSave(bool logSave)
{
    m_logSave = logSave;
}
//==============================================================================
int Settings::logCount() const
{
    return m_logCount;
}
//==============================================================================
void Settings::setLogCount(int logCount)
{
    m_logCount = logCount;
}
//==============================================================================
bool Settings::readSettings()
{
    emit toLog(tr("Read settings from file '%1'")
               .arg(file_Config), Log::LogInfo);

    QSettings ini(profilePath() + file_Config, QSettings::IniFormat);
    ini.setIniCodec("UTF-8");
    m_logSave = ini.value("log/save", true).toBool();
    m_logCount = ini.value("log/count", 10).toInt();

    return checkIniStatus(ini);
}
//==============================================================================
bool Settings::checkIniStatus(const QSettings &ini)
{
    switch (ini.status()) {
    case QSettings::NoError:
        return true;
    case QSettings::AccessError:
        m_lastError = tr("File access error '%1'").arg(file_Config);
        break;
    case QSettings::FormatError:
        m_lastError = tr("File format error '%1'").arg(file_Config);
        break;
    }

    emit toLog(m_lastError, Log::LogError);
    return false;
}
//==============================================================================
void Settings::reloadSettings()
{
    emit startReading();
    readSettings();
    emit finishReading();
}
//==============================================================================
