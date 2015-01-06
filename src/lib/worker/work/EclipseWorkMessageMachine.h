#ifndef ECLIPSEWORKMESSAGEMACHINE_H
#define ECLIPSEWORKMESSAGEMACHINE_H

#include <QObject>

#include <base/BasicName.h>

class EclipseWorkMessageMachine : public QObject
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
