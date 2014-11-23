#include "Logger.h"

#include <base/FunctionInfo.h>

#include "LogFork.h"
#include "ForkOutputBehavior.h"
#include "BuiltinOutputBehavior.h"
#include "Severity.h"
#include "TodoItem.h"

Logger::Logger(void)
    : mMaxSeverity(Severity("Null"))
    , mQuitSeverity(Severity("Quit"))
    , mExceptionSeverity(Severity("Exception"))
    , mSignalSeverity(Severity("Signal"))
{
}

void Logger::report(const LogItem item)
{

    /* Stuff happens here */

    /* Done happening */
    enqueue(item);
}

void Logger::dump(LogItem item)
{
    static const int scDumpVar = Severity("DumpVar");
    static const int scDumpHex = Severity("DumpHex");
    QByteArray ba = item.value(1).toByteArray();
    QString typeName = item.value(1).typeName();
    Severity severity(item.getSeverity());
    if (scDumpVar == severity)
    {
        item.setValue(3, typeName);
        item.setMessage("%1 = {%2} %4 %3");
    }
    else if (scDumpHex == severity)
    {
        item.setValue(3, typeName);
        item.setValue(4, hexDump(ba));
        item.setMessage("%1 = %4 %3 %5 %2!");
    }
    else
    {
        qWarning("Logger::dump() with wrong severity");
        item.setSeverity(0);
    }
    enqueue(item);
}

bool Logger::boolean(LogItem item)
{
    bool rtn = false;
    bool expected = item.value(1).toBool();
    QVariant actual = item.value(2);
    if ( ! actual.canConvert(QVariant::nameToType("bool")))
    {
        item.setValue(3, actual.typeName());
        item.setMessage("Can't convert %1 (a %4) to bool; expected %2; is %3");
    }
    else if (expected == actual.toBool())
    {
        rtn = true;
        item.setSeverityToPass();
        item.setMessage("%1 IS %2 %3!");
    }
    else
    {
        item.setMessage("%1 is NOT %2 %3!");
    }
    enqueue(item);
    return rtn;
}

bool Logger::compare(LogItem item)
{
    item.setValue(4, item.value(3).typeName());
    item.setValue(5, item.value(1).typeName());
    item.setValue(6, item.relationName());

    if ( ! item.canConvert(1, 3))
    {
        item.setMessage("Can't convert %3 (a %5) to %6; expected %2; is %4");
        return false;
    }

    bool rtn = item.evaluate(1, 3);
    if (rtn)
    {
        item.setSeverityToPass();
        item.setMessage("%1 IS %7 to %3 %2!");
    }
    else
    {
        item.setMessage("%1 %6:(%2) is NOT %7 to %3 %5:(%4)");
    }
    enqueue(item);
    return rtn;
}

bool Logger::pointer(LogItem item)
{
    static const int scAlloc = Severity("Alloc");
    static const int scPointer = Severity("Pointer");
    static const int scQPointer = Severity("QPointer");
    Severity severity(item.getSeverity());
    unsigned voidPtr = item.value(3).toUInt();
    bool rtn = !! voidPtr;

    QString sevName, passName;
    if (scAlloc == severity)
    {
        sevName =  "Allocation Failure";
        passName = "Allocation Success";
    }
    else if (scPointer == severity)
    {
        sevName = "Null Pointer";
        passName = "Good Pointer";
    }
    else if (scQPointer == severity)
    {
        sevName = "Null QObject Pointer";
        passName = "Good QObject Pointer";
    }
    else
    {
        qWarning("Logger::pointer() with wrong severity");
        item.setSeverity(0);
    }

    if (rtn)
    {
        item.setSeverityToPass();
        item.setValue(4, QString::number(voidPtr, 16));
        item.setMessage(passName+": %1 %2 %3 bytes at 0x%5");
    }
    else
    {
        item.setMessage(sevName+": %1 %2 %3 bytes %4!");
    }
    enqueue(item);
    return rtn;
}

void Logger::troll(const LogItem item)
{
    (void)item;
}

void Logger::todo(LogItem item)
{
    Severity severity(item.getSeverity());
    FunctionInfo fni = item.getFunction();
    BasicName sevName(severity.name());

    TodoItem todo(FileLinePair(fni.getSourceFile(),
                               fni.getFileLine()),
                  item.values());
    if (mTodoItemSet.contains(todo))
    {
        item.setSeverity(0);
    }
    else
    {
        mTodoItemSet.insert(todo);
        item.setMessage(sevName()+": "+fni.getPrettyFunction());
    }
    enqueue(item);
}

LogItem Logger::take(void)
{
    return mItemQueue.takeFirst();
}

LogItem::List Logger::take(int count)
{
    LogItem::List itemList;
    if (count <= 0 || count >= mItemQueue.size())
    {
        itemList = mItemQueue.toVector().toList();
        mItemQueue.clear();
    }
    else
    {
        while (count-- && ! mItemQueue.isEmpty())
            itemList << mItemQueue.takeFirst();
    }
    return itemList;
}

LogItem::List Logger::preambleItems(void) const
{
    return mPreambleList;
}

void Logger::clearForks(void)
{
    foreach (BasicName name, mNameForkMap.keys())
        unfork(name);
}

bool Logger::fork(const BasicName & forkName,
                  const QUrl & forkUrl)
{
    if (mNameForkMap.contains(forkName))
        unfork(forkName);
    LogFork * fork = new LogFork(forkName, forkUrl);
    if ( ! fork) return false;
    mNameForkMap.insert(forkName, fork);
    return fork->isError();
}

bool Logger::unfork(const BasicName & forkName)
{
    LogFork * fork = mNameForkMap.value(forkName);
    if ( ! fork) return false;
    fork->close();
    mNameForkMap.remove(forkName);
    delete fork;
    return true;
}

QStringList Logger::hexDump(const QByteArray & ba)
{
    int n = ba.size();
    QString hexString;
    hexString.reserve(n<<2);
    for (int x = 0; x < n; ++x)
        hexString.append(QString::number(ba.at(x), 16).toUpper());
    return QStringList() << hexString;
}

LogItem::Key Logger::enqueue(LogItem item)
{
    LogItem::Key key = item.getItemKey();
    Severity severity = item.getSeverity();
    if ( ! key || ! severity ) return 0;

    /* Stuff happens here */

    /* Done happening */

    /* Output to Forks */
    foreach(LogFork * fork, mNameForkMap.values()) fork->write(item);

    /* Clean up and save */
    item.clearFormatted();
    mItemQueue.enqueue(item);
    //if (Severity::Preamble == Severity(severity)) mPreambleList.append(item);
    handle(item);
    return key;
}

void Logger::handle(LogItem item)
{
    Severity severity = Severity(item.getSeverity());
    if (severity > mMaxSeverity) mMaxSeverity = severity;

    /* Stuff happens here */

    /* Done happening */

    if (severity > mSignalSeverity)
        qFatal(qPrintable("***SIGNAL: " + item.toString()));
    else if (severity > mExceptionSeverity)
        qFatal(qPrintable("***EXEPTION: " + item.toString()));
    else if (severity > mQuitSeverity)
        qFatal(qPrintable("***QUIT: " + item.toString()));
}

void Logger::staticCtor(void)
{
    ForkOutputBehavior::registerSchemes(BuiltinOutputBehavior::csmRegisteredEccs,
                                        BuiltinOutputBehavior::csmMetaName);
}
