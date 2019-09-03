#ifndef STREAMINTERFACE_H
#define STREAMINTERFACE_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>

/**	@class		StreamInterface
 *	@brief		Class for the network stream of the Raspberry Pi
 *
 *	@details
 *	This class represents the network image/video stream of the
 *  Raspberry Pi Cam.
 */
class StreamInterface: public QObject
{
    Q_OBJECT

public:
    explicit StreamInterface(QObject *parent = nullptr);
    virtual ~StreamInterface();

    static const int STREAM_PORT;

    int imageSize() const { return m_imageSize; }
    void setImageSize(int imageSize) { m_imageSize = imageSize; }

private slots:
    void newConnection();
    void readPendingImageStreamPackets();

signals:
    void newImageAvailable(QByteArray image);

private:
    QTcpServer *m_streamConnection = nullptr;
    QTcpSocket *m_streamSocket = nullptr;
    QByteArray m_currentImage;

    int m_imageSize;
    int m_bytesLeft;

};

#endif // STREAMINTERFACE_H
