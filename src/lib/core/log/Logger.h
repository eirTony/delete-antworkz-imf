#ifndef LOGGER_H
#define LOGGER_H

#include <base/BasicNameMap.h>
#include <base/BasicNameHash.h>
#include <base/FileLinePair.h>
#include <base/FunctionMap.h>

#include "LogItem.h"
#include "Severity.h"
#include "TodoItem.h"

class ItemFormatBehavior;
class LogFork;

class Logger
{
public:
    Logger(void);
    void report(const LogItem item);
    void dump(LogItem item);
    bool boolean(LogItem item);
    bool compare(LogItem item);
    bool pointer(LogItem item);
    void troll(const LogItem item);
    void todo(LogItem item);

    LogItem take(void); // one
    LogItem::List take(int count=-1); // -1=all
    LogItem::List preambleItems(void) const;

    void clearForks(void);
    bool fork(const BasicName & forkName,
              const QUrl & forkUrl);
    bool unfork(const BasicName & forkName);

public: // static
    static void staticCtor(void);

private: // maybe LoggerBehavior later
    QStringList hexDump(const QByteArray & ba);
    LogItem::Key enqueue(LogItem item);
    void handle(LogItem item);

private:
    Severity mMaxSeverity;
    Severity mQuitSeverity;
    Severity mExceptionSeverity;
    Severity mSignalSeverity;
    TodoItem::Set mTodoItemSet;
    LogItem::Queue mItemQueue;
    LogItem::List mPreambleList;
    FileLinePair::Set mFileLineSet;
    FunctionMap mFunctionMap;
    BasicNameHash<ItemFormatBehavior *> mFormatNameBehaviorHash;
    BasicNameMap<LogFork *> mNameForkMap;
};
/*! @class Logger "Logger.h" <log/Logger.h>
 * @brief The Logger class provides the engine of the Logging Facility
 * @since Started in v2.03
 *
 * A StaticSingleton instance of the Logger class provides the plumbing
 * for the Logging Facility by creating, processing, and queueing
 * LogItem instances.
 *
 * A series of functions--report, dump, boolean, compare, pointer,
 * troll, and todo--create LogItem instances then process them while
 * they are being enqueued.
 * However, these functions are rarely called directly by other
 * AntWorkz libraries or users;
 * instead they are called indirectly via both internal
 * and external MACROs.
 *
 * At LogLib's initial library level, configuation values are
 * not yet available.
 * Hence, the initial log "forks" are initiated by environment variables.
 * Once under programmatic controls forks can be opened, closed, or modified.
 */
#endif // LOGGER_H
