#ifndef CONSOLEUNO_H
#define CONSOLEUNO_H

#include <exe/ConsoleApplication.h>

class EclipseMessage;
class EclipseWorkMessageMachine;

class ConsoleUno : public ConsoleApplication
{
    Q_OBJECT
public:
    explicit ConsoleUno(void);
    void processChar(const QChar c);
    void processMessage(const EclipseMessage & msg);
    void processTerminate(const int exitCode);

signals:

public slots:
    virtual void doInitialize(BasicName::VariantMap init
                                =BasicName::VariantMap());
    virtual void doSetup(BasicId::VariantMap config
                                =BasicId::VariantMap());
    virtual void doStart(void);

signals:
    void send(const EclipseMessage & msg);

public slots:
    void receive(const EclipseMessage & msg);

private:
    EclipseWorkMessageMachine * mpEWMM = 0;
};

#endif // CONSOLEUNO_H
