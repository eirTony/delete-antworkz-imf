#include "ExecutableSupport.h"

#include <QCoreApplication>

#include <base/BasicJournalQueue.h>
//#include <base/BasicJournalInternal.h> // fix this someday
#include <base/BasicJournal.h>

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

    _BJOURNAL.setParent(this);
//  _BJOURNAL.startup(QUrl("txtfile:////Temp/AntZ"));
    _BJOURNAL.startup();
    Q_ASSERT(_BJOURNAL.startupFile());
    if (_BJOURNAL.startupFile()->isWritable())
        BTRACE1("Basic Journal started in %1",
                _BJOURNAL.startupFile()->fileName());
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
