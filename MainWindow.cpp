#include "MainWindow.h"

#include <QButtonGroup>
#include <QVector>
#include <QDebug>

//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    m_rpiStreamInterface = new StreamInterface(this);
    m_rpiControlInterface = new ControlInterface(this);

    connect(m_rpiStreamInterface, &StreamInterface::newImageAvailable, this, &MainWindow::newImageAvailable);

    connect(m_connectButton, &QPushButton::clicked, this, &MainWindow::connectButtonClicked);
    connect(m_rpiControlInterface, &ControlInterface::connectedToServer, [=]()
        {
            this->m_connectButton->setText("Connected");
            this->m_connectButton->setEnabled(false);
            m_rpiConnected = true;
        }
    );

    connect(m_closeButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
}

void MainWindow::connectButtonClicked()
{
    if (!m_rpiConnected)
    {
        m_rpiControlInterface->connectToServer(m_IpAddressLineEdit->text(), m_PorLineEdit->text().toUShort());
    }
}

void MainWindow::newImageAvailable(const QByteArray& ba)
{
    QImage::Format image_format = QImage::Format_Indexed8;
    QImage image(reinterpret_cast<const uchar*>(ba.data()), m_imageWidth, m_imageHeight, image_format);
    m_liveViewLabel->setPixmap(QPixmap::fromImage(image.copy()));
}

