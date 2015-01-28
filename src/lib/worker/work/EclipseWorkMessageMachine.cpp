#include "EclipseWorkMessageMachine.h"

#include <state/EclipseStateMachine.h>
#include <msg/EclipseMessageQueue.h>

EclipseWorkMessageMachine::EclipseWorkMessageMachine(QObject * parent)
    : QObject(parent)
{
    mpMachine = new EclipseStateMachine(this);
    mpQueue = new EclipseMessageQueue(this);
    Q_ASSERT(mpMachine);
    Q_ASSERT(mpQueue);
}

bool EclipseWorkMessageMachine::initialize(const BasicName::VariantMap & init)
{
    bool success = true;
    success |= mpMachine->initialize(init);
    success |= mpQueue->initialize(init);
    return success;
}

bool EclipseWorkMessageMachine::configure(const BasicId::VariantMap & config)
{
    bool success = true;
    success |= mpMachine->configure(config);
    success |= mpQueue->configure(config);
    return success;
}

EclipseStateMachine * EclipseWorkMessageMachine::machine(void) const
{
    return mpMachine;
}

EclipseMessageQueue * EclipseWorkMessageMachine::queue(void) const
{
    return mpQueue;
}

void EclipseWorkMessageMachine::start(void)
{
    mpMachine->start();
}
