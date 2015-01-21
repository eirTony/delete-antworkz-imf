#ifndef ANTZCONSOLE_H
#define ANTZCONSOLE_H

#include <exe/ConsoleApplication.h>

class AntzConsole : public ConsoleApplication
{
    Q_OBJECT
public:
    AntzConsole(void);
    virtual void doInitialize(BasicName::VariantMap init
                              =BasicName::VariantMap()) {}
    virtual void doSetup(BasicId::VariantMap config
                         =BasicId::VariantMap()) {}
    virtual void doStart(void);
};

#endif // ANTZCONSOLE_H
