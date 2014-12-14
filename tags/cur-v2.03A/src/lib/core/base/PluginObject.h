/*! @file PluginObject.h    BaseLib PluginObject class declaration */
#ifndef PLUGINOBJECT_H
#define PLUGINOBJECT_H
#include "BaseLib.h"

#include <QPluginLoader>
#include "ModuleInfo.h"

#include <QObject>
#include <QString.h>

class PluginObject : public QPluginLoader, public ModuleInfo
{
    Q_OBJECT

public:
    PluginObject(const QString & name,
                 const QString & type=QString(),
                 QObject * fallback=0);
    QObject * instance(void) const;
    bool isError(void) const;
    QString errorString(void) const;

signals:
    void error(QString message);

public slots:

protected slots:
    void setError(const QString & message);

private:
    QObject * mpInstance = 0;
    QObject * mpFallback = 0;
    QString mError;
    QString mPluginType;
    QString mPluginName;
};


#define PLUGIN_CLASS(MyPLUGIN, MyTYPE, MyINTERFACE, MyIID, MyFALLBACK) \
    class MyPLUGIN : public PluginObject, public MyINTERFACE \
    { \
        Q_OBJECT \
        Q_PLUGIN_METADATA(IID MyIID) \
        Q_INTERFACES(MyINTERFACE) \
    public: \
        MyPLUGIN(void) : PluginObject(MyPLUGIN, MyTYPE, MyINTERFACE) {} \
        MyPLUGIN * instance(void) const \
        { return qobject_cast<MyPLUGIN>(PluginObject::instance()); } \
        MyPLUGIN * operator () (void) const { return instance(); } \

//      User implements MyINTERFACE virtual slots
//  }; // MyPLUGIN



#endif // PLUGINOBJECT_H
