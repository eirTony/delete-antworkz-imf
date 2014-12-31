#ifndef ANTZCONSOLE_H
#define ANTZCONSOLE_H

#include <base/ModuleInfo.h>
#include <exe/ConsoleApplication.h>
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "AntzConsole"

#include <msg/EclipseMessageQueue.h>
#include <state/EclipseStateMachine.h>

class AntzConsole : public ConsoleApplication
                  , public ModuleInfo
{
    Q_OBJECT
public:
    AntzConsole(void);
    virtual void doInitialize(void) {}
    virtual void doSetup(void) {}
    virtual void doStart(void);

signals:
    void send(const EclipseMessage & msg);

public slots:
    void receive(const EclipseMessage & msg);
};

#endif // ANTZCONSOLE_H
