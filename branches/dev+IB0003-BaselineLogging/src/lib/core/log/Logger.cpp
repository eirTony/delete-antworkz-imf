#include "Logger.h"

#include <base/FunctionInfo.h>

#include "LogFork.h"
#include "Severity.h"
#include "TodoItem.h"

Logger::Logger(void)
    : mMaxSeverity(Severity::nullLevel)
    , mQuitSeverity(Severity::Quit)
    , mExceptionSeverity(Severity::Exception)
    , mSignalSeverity(Severity::Signal)
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
    QString varName = item.value(0).toString();
    QByteArray ba = item.value(1).toByteArray();
    QString typeName = item.value(1).typeName();
    int bytes = item.value(2).toInt();
    Severity severity(item.getSeverity());

    switch (int(severity))
    {
    case Severity::DumpVar:
        item.setValue(3, typeName);
        item.setMessage("%1 = {%2} %4 %3");
        break;

    case Severity::DumpHex:
        item.setValue(3, typeName);
        item.setValue(4, hexDump(ba));
        item.setMessage("%1 = %4 %3 %5 %2!");
        break;

    default:
        qWarning("Logger::dump() with wrong severity");
        return;
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

}

bool Logger::alloc(LogItem item)
{

}

void Logger::troll(const LogItem item)
{

}

void Logger::todo(LogItem item)
{
    Severity severity(item.getSeverity());
    FunctionInfo fni = item.getFunction();
    if ( ! (Severity::Todo == severity
         || Severity::NeedDo == severity
         || Severity::MustDo == severity))
    {
        qWarning("Logger::todo() with wrong severity");
        return;
    }

    TodoItem todo(FileLinePair(fni.getSourceFile(),
                               fni.getFileLine()),
                  item.values());
    if (mTodoItemSet.contains(todo))
    {
        item.setSeverity(Severity::nullLevel);
    }
    else
    {
        mTodoItemSet.insert(todo);
    }
    enqueue(item);
}

LogItem Logger::take(void)
{

}

LogItem::List Logger::take(const int count)
{

}

LogItem::List Logger::preambleItems(void) const
{

}

void Logger::clearForks(void)
{

}

bool Logger::fork(const BasicName & forkName,
          const QUrl & forkUrl)
{

}

bool Logger::unfork(const BasicName & forkName)
{

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
    if (Severity::Preamble == Severity(severity)) mPreambleList.append(item);
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
