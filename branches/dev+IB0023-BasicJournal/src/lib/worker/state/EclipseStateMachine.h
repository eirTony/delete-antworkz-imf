#ifndef ECLIPSESTATEMACHINE_H
#define ECLIPSESTATEMACHINE_H
#include "StateLib.h"

#include <QStateMachine>

#include <base/BasicId.h>
#include <base/BasicName.h>

#include "StateMachineConfiguration.h"

class STATESHARED_EXPORT EclipseStateMachine : public QStateMachine
{
    Q_OBJECT
public:
    explicit EclipseStateMachine(QObject * parent=0);
    bool initialize(const BasicName::VariantMap init
                                =BasicName::VariantMap());
    bool configure(const BasicId::VariantMap config
                                =BasicId::VariantMap());
    void setExitCode(const int code);

signals:
    void active(void);
    void terminating(void);
    void terminated(void);

public slots:
    void start(void);
    void terminate(void);
    void terminate(const int exitCode);

private slots:
    void enterFinal(void);

private:
    int mExitCode = 0;
};

#endif // ECLIPSESTATEMACHINE_H
