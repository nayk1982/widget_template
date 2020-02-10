#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include "Log"
//==============================================================================
class Settings : public QObject
{
    Q_OBJECT
    const QString file_Config {"settings.conf"};
    const QString file_Params {"parameters.save"};

public:
    explicit Settings(QObject *parent = nullptr);
    bool saveSettings();
    QString applicationPath() const;
    QString profilePath() const;
    QString lastError() const;
    bool writeParameter(const QString &name, QVariant value) const;
    QVariant readParameter(const QString &name, QVariant defaultValue = QVariant()) const;
    bool debug() const;
    bool logSave() const;
    void setLogSave(bool logSave);
    int logCount() const;
    void setLogCount(int logCount);

signals:
    void toLog(const QString &text, nayk::Log::LogType logType = nayk::Log::LogInfo);
    void startReading();
    void finishReading();
    void startWrite();
    void finishWrite();

private:
    bool m_debug {false};
    bool m_logSave {false};
    int m_logCount {10};
    QString m_lastError {""};

    bool readSettings();
    bool checkIniStatus(const QSettings &ini);

public slots:
    void reloadSettings();
};
//==============================================================================
#endif // SETTINGS_H
