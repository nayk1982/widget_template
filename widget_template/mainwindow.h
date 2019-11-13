#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

#include "Log"
#include "DialogLog"

//==================================================================================================

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//==================================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void toLog(const QString &text, nayk::Log::LogType logType = nayk::Log::LogInfo);

private:
    Ui::MainWindow *ui;
    nayk::Log *log {nullptr};
    nayk::DialogLog *dialogLog {nullptr};

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_actionExit_triggered();
    void on_actionToolBar_triggered(bool checked);
    void on_actionSettings_triggered();
    void on_actionAbout_triggered();
};

//==================================================================================================
#endif // MAINWINDOW_H
