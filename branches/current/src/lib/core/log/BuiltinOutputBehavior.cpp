#include "BuiltinOutputBehavior.h"

#include <QtDebug>
#include <QFile>
#include <QTextStream>

#include <base/BasicName.h>

#include "LogFork.h"

const QByteArray BuiltinOutputBehavior::csmMetaName("BuiltinOutputBehavior");
const EightCC BuiltinOutputBehavior::csmStdout("stdout");
const EightCC BuiltinOutputBehavior::csmStderr("stderr");
const EightCC BuiltinOutputBehavior::csmTxtFile("txtfile");
const EightCC BuiltinOutputBehavior::csmTroll("troll");
const EightCCList BuiltinOutputBehavior::csmRegisteredEccs
                            = EightCCList()     << csmStdout
                                                << csmStderr
                                                << csmTxtFile
                                                << csmTroll;

BuiltinOutputBehavior::BuiltinOutputBehavior(void)
{
}

bool BuiltinOutputBehavior::open(void)
{
    if (csmTroll == mSchemeEcc)
    {
        QVariant varWarning  = mpFork->urlOption( "WarningSeverity");
        QVariant varCritical = mpFork->urlOption("CriticalSeverity");
        if ( !  varWarning.isNull())
            mWarningSeverity  = Severity(varWarning.toInt());
        if ( ! varCritical.isNull())
            mCriticalSeverity = Severity(varCritical.toInt());
        // handle QtDebug
        return true;
    }

    if (csmTxtFile == mSchemeEcc)
    {
        QString filePath = mUrl.path();
        mpFile = new QFile(filePath);
        if (mpFile)
            if ( ! mpFile->open(QIODevice::WriteOnly))
                return mpFork->setError("Unable to open file: "+filePath);
        mpStream = new QTextStream((QIODevice *)mpFile);
    }
    else if (csmStderr == mSchemeEcc)
    {
        mpStream = new QTextStream(stderr, QIODevice::WriteOnly);
    }
    else if (csmStdout == mSchemeEcc)
    {
        mpStream = new QTextStream(stdout, QIODevice::WriteOnly);
    }
    else
    {
        qWarning(qPrintable("Invalid SchemeEcc in"
                            " BuiltinOutputBehavior::open(): "
                            + mSchemeEcc));
        return false;
    }
    if (mpStream && QTextStream::Ok != mpStream->status())
        return mpFork->setStarted();
    else
        return mpFork->setError("Unable to open text stream");
}

bool BuiltinOutputBehavior::write(const Severity severity,
                                  const QString & message)
{
    if (mpFork->isNotMinMax(severity))
        return true; // Success because not within Min/Max

    if (mpStream)
    {
        *mpStream << message << endl;
        return true;
    }

    if (csmTroll == mSchemeEcc)
    {
        if (severity >= mCriticalSeverity)
            qCritical(qPrintable(message));
        else if (severity >= mWarningSeverity)
            qWarning(qPrintable(message));
        else
            qDebug(qPrintable(message));
        return true;
    }

    return false;
}

bool BuiltinOutputBehavior::flush(void)
{
    if (csmTroll == mSchemeEcc)
        return true;
    if (mpStream)
    {
        mpStream->flush();
        return true;
    }
    return false;
}

void BuiltinOutputBehavior::close(void)
{
    if (mpStream)
    {
        delete mpStream;
        mpStream = 0;
    }
    if (mpFile)
    {
        mpFile->close();
        delete mpFile;
        mpFile = 0;
    }
}
