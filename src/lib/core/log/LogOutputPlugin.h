#ifndef LOGOUTPUTPLUGIN_H
#define LOGOUTPUTPLUGIN_H

#include "LogOutputInterface.h"

#include <base/BasicName.h>

class LogFork;

class LOGSHARED_EXPORT LogOutputPlugin : public LogOutputInterface
{
    Q_OBJECT
public:
    LogOutputPlugin(const BasicName & name,
                    const BasicName::List & aliases,
                    LogFork * fork,
                    QObject * parent=0);
    LogOutputPlugin(const BasicName & name,
                    LogFork * fork,
                    QObject * parent=0);
    virtual bool open(void) {}
    virtual bool write(const Severity & sev,
                       const QString & message) {}
    virtual bool write(const LogItem & item) {}
    virtual bool flush(void) {}
    virtual void close(void) {}

signals:

public slots:

};

#endif // LOGOUTPUTPLUGIN_H
