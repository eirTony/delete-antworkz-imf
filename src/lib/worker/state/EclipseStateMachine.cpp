#include "EclipseStateMachine.h"

EclipseStateMachine::EclipseStateMachine(QObject * parent)
    : QStateMachine(parent)
{
    setObjectName("EclipseStateMachine");
}
