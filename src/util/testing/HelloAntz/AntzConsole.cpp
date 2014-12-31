#include "AntzConsole.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QTimer>

AntzConsole::AntzConsole(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
    QObject::setObjectName("AntzConsole");
}

void AntzConsole::doStart(void)
{
    EclipseMessage msg;
    EclipseMessageQueue * msgQ = new EclipseMessageQueue(this);
    connect(this, SIGNAL(send(const EclipseMessage &)),
            msgQ, SLOT(incoming(const EclipseMessage &)));
    connect(msgQ, SIGNAL(outgoing(const EclipseMessage &)),
            this, SLOT(receive(const EclipseMessage &)));
    msg.insert("Message", "This is a message.");

    EclipseStateMachine * sm = new EclipseStateMachine(this);

    SerialExecutable::writeLine("Hello Antz!");
    emit send(msg);
    SerialExecutable::writeError("This may be an error?!");
    QTimer::singleShot(5000, this, SLOT(quit()));
}

void AntzConsole::receive(const EclipseMessage & msg)
{
    SerialExecutable::writeLine(msg["Message"].toString());
}
