#include "StreamInterface.h"

const int StreamInterface::STREAM_PORT = 8082;

StreamInterface::StreamInterface(QObject *parent)
    :QObject (parent),
    m_bytesLeft(0)
{
    m_streamConnection = new QTcpServer(this);
    connect(m_streamConnection, &QTcpServer::newConnection, this, &StreamInterface::newConnection);
    m_streamConnection->listen(QHostAddress::AnyIPv4, STREAM_PORT);
}

StreamInterface::~StreamInterface()
{
}


//----------------------------------------------------
void StreamInterface::newConnection()
{
    m_streamSocket = m_streamConnection->nextPendingConnection();
    connect(m_streamSocket, &QTcpSocket::readyRead,
            this, &StreamInterface::readPendingImageStreamPackets);
}


//----------------------------------------------------
void StreamInterface::readPendingImageStreamPackets()
{
    QByteArray currentPacket = m_streamSocket->read(m_bytesLeft);
    auto bytesReceived = currentPacket.size();

    m_bytesLeft -= bytesReceived;

    m_currentImage.append(currentPacket);

    if (0 == m_bytesLeft)
    {
        m_bytesLeft = m_imageHeight*m_imageWidth;
        emit newImageAvailable(m_currentImage);
        m_currentImage.clear();
    }
}

int StreamInterface::imageHeight() const
{
    return m_imageHeight;
}

int StreamInterface::imageWidth() const
{
    return m_imageWidth;
}
