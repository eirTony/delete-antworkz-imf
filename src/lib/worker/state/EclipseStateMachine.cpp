#include "EclipseStateMachine.h"

#include <QFinalState>

EclipseStateMachine::EclipseStateMachine(QObject * parent)
    : QStateMachine(parent)
{
    setObjectName("EclipseStateMachine");
}

bool EclipseStateMachine::initialize(const BasicName::VariantMap init)
{
    (void)init;
    QState * activeState = new QState(this);
    activeState->setObjectName("activeState");
    QFinalState * finalState = new QFinalState(this);
    finalState->setObjectName("finalState");
    addTransition(this, SIGNAL(terminating()), finalState);
    setInitialState(activeState);
    connect(finalState, SIGNAL(entered()), this, SLOT(enterFinal()));
    return true;
}

bool EclipseStateMachine::configure(const BasicId::VariantMap config)
{
    (void)config;
    return true;
}

void EclipseStateMachine::setExitCode(const int code)
{
    mExitCode = code;
}

void EclipseStateMachine::start(void) // [slot]
{
    QStateMachine::start();
    emit active();
}

void EclipseStateMachine::terminate(const int exitCode) // [slot]
{
    mExitCode = exitCode;
    terminate();
}

void EclipseStateMachine::terminate(void) // [slot]
{
    emit terminating();
}

void EclipseStateMachine::enterFinal(void) // [slot]
{
    emit terminated();
}
