#include "ConsoleUno.h"
#include "Version.h"
#include <CommonVersion.h>
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "ConsoleUno"

#include <QTimer>

#include <msg/EclipseMessage.h>
#include <msg/EclipseMessageQueue.h>
#include <state/EclipseStateMachine.h>
#include <work/EclipseWorkMessageMachine.h>

ConsoleUno::ConsoleUno(void)
    : mpEWMM(new EclipseWorkMessageMachine(this))
{
    setVersion();
    QObject::setObjectName("ConsoleUno");
}

void ConsoleUno::doInitialize(BasicName::VariantMap init)
{

}

void ConsoleUno::doSetup(BasicId::VariantMap config)
{

}

void ConsoleUno::doStart(void)
{
    SerialExecutable::writeLine("Hello from ConsoleUno!");

    EclipseMessage msg;
    EclipseMessageQueue * msgQ = new EclipseMessageQueue(this);
    connect(this, SIGNAL(send(const EclipseMessage &)),
            msgQ, SLOT(incoming(const EclipseMessage &)));
    connect(msgQ, SIGNAL(outgoing(const EclipseMessage &)),
            this, SLOT(receive(const EclipseMessage &)));
    msg.insert("Message", "This is a message.");
    emit send(msg);

    EclipseStateMachine * sm = new EclipseStateMachine(this);

    QTimer::singleShot(5000, this, SLOT(quit()));
}

void ConsoleUno::receive(const EclipseMessage & msg)
{
    SerialExecutable::writeLine(msg["Message"].toString());
}
