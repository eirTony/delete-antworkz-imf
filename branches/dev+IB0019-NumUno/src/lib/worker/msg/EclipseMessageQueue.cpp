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

void EclipseMessageQueue::send(const EclipseMessage & msg)
{
    qDebug(qPrintable("EclipseMessageQueue::send(msg) with msg="
                      +msg["Message"].toString()));
    mpCurrentSenderObject = QObject::sender();
    mCurrentMessage = msg;
}
