#ifndef LOGOUTPUTINTERFACE_H
#define LOGOUTPUTINTERFACE_H
#include "LogLib.h"

#include <QObject>

class LogFork;
class LogItem;
class LogOutputPlugin;
class Severity;

class LOGSHARED_EXPORT LogOutputInterface : public QObject
{
    Q_OBJECT
public:
    LogOutputInterface(LogFork * fork,
                       LogOutputPlugin * plugin,
                       QObject * parent=0);
    virtual ~LogOutputInterface() {}

public: // pure virtual
    virtual bool open(void) = 0;
    virtual bool write(const Severity & sev,
                       const QString & message) = 0;
    virtual bool write(const LogItem & item) = 0;
    virtual bool flush(void) = 0;
    virtual void close(void) = 0;

signals:

public slots:

private:
    LogFork * mpFork = 0;
    LogOutputPlugin * mpPlugin = 0;
};

#endif // LOGOUTPUTINTERFACE_H
