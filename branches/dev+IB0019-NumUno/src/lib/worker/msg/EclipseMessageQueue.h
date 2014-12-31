#ifndef ECLIPSEMESSAGEQUEUE_H
#define ECLIPSEMESSAGEQUEUE_H
#include "MsgLib.h"

#include <QObject>

#include <type/QQQueue.h>

class MSGSHARED_EXPORT EclipseMessageQueue : public QObject
{
    Q_OBJECT
public:
    explicit EclipseMessageQueue(QObject * parent=0);

signals:
    void outgoing(const EclipseMessage & msg);

public slots:
    void incoming(const EclipseMessage & msg);

private:
    QQQueue<EclipseMessage> mQueue;
    QObject * mpCurrentSenderObject = 0;
    EclipseMessage mCurrentMessage;
};

#endif // ECLIPSEMESSAGEQUEUE_H
