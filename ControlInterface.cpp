#include "ControlInterface.h"

ControlInterface::ControlInterface(QObject *parent)
    :QObject (parent)
{
}

ControlInterface::~ControlInterface()
{
    socket_.disconnectFromHost();
    socket_.close();
}

void ControlInterface::connectToServer(const QString& ipAddr, uint16_t port)
{
    QByteArray data("hello");

    socket_.connectToHost(ipAddr, port);
    if( socket_.waitForConnected(3000) )
    {
        socket_.write( data );
        emit connectedToServer();
    }
}
