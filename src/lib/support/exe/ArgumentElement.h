#ifndef ARGUMENTELEMENT_H
#define ARGUMENTELEMENT_H
#include "ExeLib.h"

#include <type/DProperty.h>

#define ARGUMENTELEMENT_DATAPROPS(TND) \
    TND(quint64, ElementKey, 0) \

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
};

#endif // ARGUMENTELEMENT_H
