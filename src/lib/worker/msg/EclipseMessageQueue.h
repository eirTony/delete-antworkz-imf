#ifndef ECLIPSEMESSAGEQUEUE_H
#define ECLIPSEMESSAGEQUEUE_H
#include "MsgLib.h"

#include <QObject>

#include <base/BasicId.h>
#include <base/BasicName.h>
#include <type/QQQueue.h>

#include "EclipseMessage.h"

class MSGSHARED_EXPORT EclipseMessageQueue : public QObject
{
    Q_OBJECT
public:
    explicit EclipseMessageQueue(QObject * parent=0);
    bool initialize(const BasicName::VariantMap init=BasicName::VariantMap());
    bool configure(const BasicId::VariantMap config
                                =BasicId::VariantMap());

signals:
    void outgoing(const EclipseMessage & msg);
    void received(const EclipseMessage & msg);
    void announce(const EclipseMessage & msg);

public slots:
    void incoming(const EclipseMessage & msg);
    void send(const EclipseMessage & msg);

private:
    QQQueue<EclipseMessage> mQueue;
    QObject * mpCurrentSenderObject = 0;
    EclipseMessage mCurrentMessage;
};

#endif // ECLIPSEMESSAGEQUEUE_H
