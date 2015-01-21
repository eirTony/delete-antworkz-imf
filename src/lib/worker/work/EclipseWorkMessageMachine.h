#ifndef ECLIPSEWORKMESSAGEMACHINE_H
#define ECLIPSEWORKMESSAGEMACHINE_H
#include "WorkLib.h"

#include <QObject>

#include <base/BasicName.h>

class WORKSHARED_EXPORT EclipseWorkMessageMachine : public QObject
{
    Q_OBJECT
public:
    explicit EclipseWorkMessageMachine(QObject * parent=0);
    bool initialize(const BasicName::VariantMap & init
                            =BasicName::VariantMap());
signals:

public slots:

};

#endif // ECLIPSEWORKMESSAGEMACHINE_H
