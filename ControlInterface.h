#ifndef CONTROLINTERFACE_H
#define CONTROLINTERFACE_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>


/**	@class		ControlInterface
 *	@brief		Class for controlling the Raspberry Pi via network
 *
 *	@details
 *	This class provides network interface functionality to control a
 *  Raspberry Pi via network.
 */
class ControlInterface : public QObject
{
    Q_OBJECT

public:
    enum ConnectionState {
        CONNECTED,
        DISCONNECTED
    };

    explicit ControlInterface(QObject *parent = nullptr);
    ~ControlInterface();

    void connectToServer(const QString& ipAddr, uint16_t port);

signals:
    void connectedToServer();

private:
    QTcpSocket socket_;
    ConnectionState connectionState_ = DISCONNECTED;
};

#endif // CONTROLINTERFACE_H
