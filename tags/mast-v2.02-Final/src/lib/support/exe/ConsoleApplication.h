#ifndef CONSOLEEXECUTABLE_H
#define CONSOLEEXECUTABLE_H
#include "ExeLib.h"

#include "SerialExecutable.h"

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
    virtual void doInitialize(void) = 0;
    virtual void doSetup(void) = 0;
    virtual void doStart(void) = 0;

private:
    StandardStream * mpStream = 0;
};

#endif // CONSOLEEXECUTABLE_H
