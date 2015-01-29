#ifndef ECLIPSEWORKSUPERVISOR_H
#define ECLIPSEWORKSUPERVISOR_H

#include <QObject>

class EclipseMessage;

class EclipseWorkMessageMachine;

class EclipseWorkSupervisor : public QObject
{
    Q_OBJECT
public:
    explicit EclipseWorkSupervisor(EclipseWorkMessageMachine * boss=0);

signals:
    void error(const QString & errorString);
    void result(const EclipseMessage & msg);

public slots:
    void execute(const EclipseMessage & msg);

private:
    void ExecuteEnquriry(void); // emit result(msg)

private:
    EclipseWorkMessageMachine * mpEWMM = 0;
};

#endif // ECLIPSEWORKSUPERVISOR_H
