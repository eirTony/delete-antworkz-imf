#ifndef ECLIPSEWORKMESSAGEMACHINE_H
#define ECLIPSEWORKMESSAGEMACHINE_H
#include "WorkLib.h"

#include <QObject>

#include <base/BasicId.h>
#include <base/BasicName.h>

class EclipseStateMachine;
class EclipseMessageQueue;

class WORKSHARED_EXPORT EclipseWorkMessageMachine : public QObject
{
    Q_OBJECT
public:
    explicit EclipseWorkMessageMachine(QObject * parent=0);
    bool initialize(const BasicName::VariantMap & init
                            =BasicName::VariantMap());
    bool configure(const BasicId::VariantMap & config
                            =BasicId::VariantMap());
    EclipseStateMachine * machine(void) const;
    EclipseMessageQueue * queue(void) const;

signals:

public slots:
    void start(void);
    void terminate(void);

private:
    EclipseStateMachine * mpMachine = 0;
    EclipseMessageQueue * mpQueue = 0;
};

#endif // ECLIPSEWORKMESSAGEMACHINE_H
