#ifndef LOGOUTPUTPLUGIN_H
#define LOGOUTPUTPLUGIN_H
#include "LogLib.h"

#include "LogOutputInterface.h"
#include <base/AbstractPlugin.h>

#include <base/BasicName.h>
#include <base/FunctionInfo.h>

#include "Severity.h"

class LogFork;

class LOGSHARED_EXPORT LogOutputPlugin
        : public LogOutputInterface
        , public AbstractPlugin
{
    Q_OBJECT
public:
    LogOutputPlugin(const BasicName & name,
                    LogFork * fork,
                    QObject * parent=0);
    LogOutputPlugin(const BasicName & name,
                    const EightCCList &schemata,
                    LogFork * fork,
                    QObject * parent=0);
    LogOutputPlugin * instance(void) const;
    LogOutputPlugin * operator () (void) const;
    bool isWritable(void) const;
    bool configure(const BasicName::VariantMap config);

public: // pure virtual reimplementation (in derrived plugins)
    virtual bool open(void) {}
    virtual bool write(const Severity & sev,
                       const QString & message) {}
    virtual bool write(const LogItem & item) {}
    virtual bool flush(void) {}
    virtual void close(void) {}

signals:
    void newConfig(BasicName::VariantMap config);

public slots:



protected:
    void setWritable(const bool is=true);

protected slots:


protected:
    Severity mMinSeverity;
    Severity mMaxSeverity;
    Severity::List mFilterSeverityList;
    FunctionInfo mFocusFni;

private:
    bool mWritable = false;
};

#endif // LOGOUTPUTPLUGIN_H
