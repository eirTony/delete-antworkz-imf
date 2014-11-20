#include "ExecutableSupport.h"

#include <QCoreApplication>

ExecutableSupport::ExecutableSupport(ApplicationClass appClass)
    : mApplicationClass(appClass)
{
    switch (mApplicationClass)
    {
    case Widget:    mpApplication = (QApplication *)qApp;       // fall thru
    case Gui:       mpGuiApplication = (QGuiApplication *)qApp; // fall thru
    case Serial:
    case Headless:  mpCoreApplication = qApp;
        mRawApplicationArguments = mpCoreApplication->arguments();
        mExeFileInfo.setFile(mRawApplicationArguments.first());
        QObject::setParent(mpCoreApplication);
        break;

    default:
        //ASSERT("Bad ApplicationClass");
        break;
    }
}

const QFileInfo & ExecutableSupport::exeFileInfo(void) const
{
    return mExeFileInfo;
}


void ExecutableSupport::initialize(void)
{
    connect(this, SIGNAL(quitApp()),
            mpCoreApplication, SLOT(quit()));
}

void ExecutableSupport::setup(void)
{
    // do stuff
}

void ExecutableSupport::start(void)
{
    // do stuff
}

void ExecutableSupport::quit(void)
{
    emit quitApp();
}
