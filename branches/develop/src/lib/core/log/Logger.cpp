#include "Logger.h"

#include "LogFork.h"
#include "LogLevel.h"
#include "TodoItem.h"

Logger::Logger(void)
    : mMaxLevel(LogLevel::nullLevel)
    , mQuitLevel(LogLevel::Quit)
    , mExceptionLevel(LogLevel::Exception)
    , mSignalLevel(LogLevel::Signal)
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
    LogLevel level(item.getLevel());

    switch (int(level))
    {
    case LogLevel::DumpVar:
        item.setValue(3, typeName);
        item.setMessage("%1 = {%2} %4 %3");
        break;

    case LogLevel::DumpHex:
        item.setValue(3, typeName);
        item.setValue(4, hexDump(ba));
        item.setMessage("%1 = %4 %3 %5 %2!");
        break;

    default:
        qWarning("Logger::dump() with wrong level");
        return;
    }

    enqueue(item);
}

bool Logger::boolean(LogItem item)
{
    bool rtn = false;
    BasicName varName(item.value(0).toString());
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
        item.setLevelToPass();
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
    /*
    LogLevel level(item.getLevel());
    TodoItem todo(item.getFileName(),
                  item.getFileLine(),
                  item.values());
    if (mTodoSet.contains(todo))
    {
        item.setLevel(LogLevel::nullLevel);
    }
    else
    {
        mTodoSet.insert(todo);
    }
    */
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
    LogLevel level = item.getLevel();
    if ( ! key || ! level ) return 0;

    /* Stuff happens here */

    /* Done happening */

    /* Output to Forks */
    //foreach(LogFork * fork, mNameForkMap.values()) fork->write(item);

    /* Clean up and save */
    item.clearFormatted();
    mItemQueue.enqueue(item);
    if (LogLevel::Preamble == LogLevel(level)) mPreambleList.append(item);
    handle(item);
    return key;
}

void Logger::handle(LogItem item)
{
    LogLevel level = LogLevel(item.getLevel());
    if (level > mMaxLevel) mMaxLevel = level;

    /* Stuff happens here */

    /* Done happening */

    if (level > mSignalLevel)
        qFatal(qPrintable("***SIGNAL: " + item.toString()));
    else if (level > mExceptionLevel)
        qFatal(qPrintable("***EXEPTION: " + item.toString()));
    else if (level > mQuitLevel)
        qFatal(qPrintable("***QUIT: " + item.toString()));
}
