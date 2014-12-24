#ifndef ECLIPSESTATEMACHINE_H
#define ECLIPSESTATEMACHINE_H
#include "StateLib.h"

#include <QStateMachine>

#include <base/BasicName.h>

#include "StateMachineConfiguration.h"

class STATESHARED_EXPORT EclipseStateMachine : public QStateMachine
{
    Q_OBJECT
public:
    explicit EclipseStateMachine(QObject * parent=0);
    bool initialize(const BasicName::VariantMap init=BasicName::VariantMap());
    bool configure(const StateMachineConfiguration config
                                =StateMachineConfiguration());
    void setExitCode(const int code);

signals:
    void active(void);
    void terminated(void);

public slots:
    void start(void) {}
    void terminate(void) {}
    void terminate(const int exitCode) {}

private:
    int mExitCode = 0;
};

#endif // ECLIPSESTATEMACHINE_H
