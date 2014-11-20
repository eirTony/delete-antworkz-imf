#ifndef ANTZCONSOLE_H
#define ANTZCONSOLE_H

#include <base/ModuleInfo.h>
#include <exe/ConsoleApplication.h>
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "AntzConsole"

class AntzConsole : public ConsoleApplication
                  , public ModuleInfo
{
public:
    AntzConsole(void);
    virtual void doInitialize(void) {}
    virtual void doSetup(void) {}
    virtual void doStart(void);
};

#endif // ANTZCONSOLE_H
