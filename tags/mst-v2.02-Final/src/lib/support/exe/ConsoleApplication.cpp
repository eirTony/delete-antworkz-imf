#include "ConsoleApplication.h"

#include <QCoreApplication>
#include <QTimer>

#include "StandardStream.h"

ConsoleApplication::ConsoleApplication(void)
{
    mpStream = new StandardStream;    Q_ASSERT(mpStream);
    SerialExecutable::setStream(mpStream);
    QTimer::singleShot(100, this, SLOT(initialize()));
}

ConsoleApplication::~ConsoleApplication()
{
    // kill children
    // and clean up the mess
}

void ConsoleApplication::initialize(void)
{
    SerialExecutable::initialize();
    connect(this, SIGNAL(initialized()), this, SLOT(setup()));
    connect(this, SIGNAL(setuped()), this, SLOT(start()));
    // do stuff
    doInitialize();
    emit (initialized());
}

void ConsoleApplication::setup(void)
{
    SerialExecutable::setup();
    // do stuff
    doSetup();
    emit (setuped());
}

void ConsoleApplication::start(void)
{
    SerialExecutable::start();
    // do stuff
    doStart();
    emit (started());
}
