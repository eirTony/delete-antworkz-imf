#include "EclipseMessageQueue.h"

#include "EclipseMessage.h"

EclipseMessageQueue::EclipseMessageQueue(QObject * parent)
    : QObject(parent)
{
    setObjectName("EclipseMessageQueue");
}

bool EclipseMessageQueue::initialize(const BasicName::VariantMap init)
{
    return false;
}

bool EclipseMessageQueue::configure(const BasicId::VariantMap config)
{
    return false;
}

void EclipseMessageQueue::incoming(const EclipseMessage & msg)
{
    mpCurrentSenderObject = QObject::sender();
    mCurrentMessage = msg;
    emit outgoing(msg);
}

void EclipseMessageQueue::send(const EclipseMessage & msg)
{
    mpCurrentSenderObject = QObject::sender();
    mCurrentMessage = msg;
}
