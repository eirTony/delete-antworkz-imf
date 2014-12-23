#include "EclipseMessageQueue.h"

EclipseMessageQueue::EclipseMessageQueue(QObject * parent)
    : QObject(parent)
{
    setObjectName("EclipseMessageQueue");
}

void EclipseMessageQueue::incoming(const EclipseMessage & msg)
{
    qDebug("EclipseMessageQueue::incoming(const EclipseMessage & msg)");
    qDebug(qPrintable("with msg="+msg["Message"].toString()));

    mpCurrentSenderObject = QObject::sender();
    mCurrentMessage = msg;
    emit outgoing(msg);
}
