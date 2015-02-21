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
    void processMessage(const EclipseMessage & msg);

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
    void onActive(void);
    void receive(const EclipseMessage & msg);
    void onTerminated(void);

private:
    EclipseWorkMessageMachine * mpEWMM = 0;
};

#endif // CONSOLEUNO_H
