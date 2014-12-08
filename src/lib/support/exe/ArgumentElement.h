#ifndef ARGUMENTELEMENT_H
#define ARGUMENTELEMENT_H
#include "ExeLib.h"

#include <QList>

#include <base/BasicId.h>
#include <type/DProperty.h>
#include <type/QQString.h>
#include <type/QQVariant.h>
#include <type/QQUrl.h>
#include <kid/UniversalKey.h>

#define ARGUMENTELEMENT_DATAPROPS(TND) \
    TND(UniversalKey, ElementKey, UniversalKey()) \
    TND(QQString, ElementString, QQString()) \
    TND(UniversalKeyList, ParentKeys, UniversalKeyList()) \
    TND(UniversalKeyList, ChildKeys, UniversalKeyList()) \
    TND(QQUrl, SourceUrl, QQUrl()) \
    TND(BasicId, ConfigId, BasicId()) \
    TND(QQVariant, ConfigValue, QQVariant()) \
    TND(QQString, ArgumentString, QQString()) \
    TND(int, ElementState, 0) \

class EXESHARED_EXPORT ArgumentElementData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(ARGUMENTELEMENT_DATAPROPS)
public:
    ArgumentElementData(void)
    {
        DEFINE_DATAPROPS_CTORS(ARGUMENTELEMENT_DATAPROPS)
    }
};

class EXESHARED_EXPORT ArgumentElement
{
    DECLARE_PARENT_DATAPROPS(ARGUMENTELEMENT_DATAPROPS)
    DECLARE_DATAPROPS(ArgumentElement, ArgumentElementData)
public:
    enum State
    {
        nullState = 0,
        Ctor,
        Populated,
        Processed,
        Read,
        Finished,
        sizeState
    };
    typedef QList<ArgumentElement> List;

public:
    bool isNull(void) const;
    bool isSource(void) const;
    bool isParseable(void) const;
    bool isConfiguration(void) const;
    bool isUnknown(void) const;

private:
    List mChildList;
};

typedef QList<ArgumentElement> ArgumentElementList;

#endif // ARGUMENTELEMENT_H
