#include "EclipseWorkSupervisor.h"

#include "EclipseWorkMessageMachine.h"

EclipseWorkSupervisor::EclipseWorkSupervisor(EclipseWorkMessageMachine * boss)
    : QObject(boss)
{
}

void EclipseWorkSupervisor::execute(const EclipseMessage & msg)
{

}
