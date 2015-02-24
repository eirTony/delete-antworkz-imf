#ifndef CONSOLEEXECUTABLE_H
#define CONSOLEEXECUTABLE_H
#include "ExeLib.h"

#include "SerialExecutable.h"

#include <base/BasicName.h>
#include <base/BasicId.h>

class StandardStream;

class EXESHARED_EXPORT ConsoleApplication : public SerialExecutable
{
    Q_OBJECT
public:
    explicit ConsoleApplication(void);
    ~ConsoleApplication();

signals:
    void initialized(void);
    void setuped(void);
    void started(void);

public slots:
    void initialize(void);
    void setup(void);
    void start(void);

protected:
    virtual void doInitialize(BasicName::VariantMap init
                                =BasicName::VariantMap()) = 0;
    virtual void doSetup(BasicId::VariantMap config
                                =BasicId::VariantMap()) = 0;
    virtual void doStart(void) = 0;

private:
    StandardStream * mpStream = 0;
};

#endif // CONSOLEEXECUTABLE_H
