#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"

#include "StreamInterface.h"
#include "ControlInterface.h"

/**
 *	@brief The main window of the app.
 *
 *	@details
 *	Class for the main window of the GUI application.
 */
class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connectButtonClicked();

    void newImageAvailable(const QByteArray& ba);

private:

    StreamInterface *m_rpiStreamInterface = nullptr;
    ControlInterface *m_rpiControlInterface = nullptr;

    bool m_rpiConnected = false;

    const int m_imageWidth = 640;
    const int m_imageHeight = 480;
};

#endif // MAINWINDOW_H
