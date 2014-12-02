#ifndef LOGITEM_H
#define LOGITEM_H
#include "LogLib.h"

#include <type/DProperty.h>

#include <QList>
#include <QQueue>

#include <base/BasicNameHash.h>
#include <base/FunctionInfo.h>

#define LOGITEM_DATAPROPS(TND) \
    TND(quint64, ItemKey, 0) \
    TND(qint64, TimeStamp, 0) \
    TND(FunctionInfo, Function, FunctionInfo()) \
    TND(int, Level, 0) \
    TND(QString, Message, QString()) \


class LogItemData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(LOGITEM_DATAPROPS)
public:
    LogItemData(void)
    {
        DEFINE_DATAPROPS_CTORS(LOGITEM_DATAPROPS)
    }
};

class LOGSHARED_EXPORT LogItem
{
public:
    typedef quint64 Key;
    typedef QList<LogItem> List;
    typedef QQueue<LogItem> Queue;

    DECLARE_PARENT_DATAPROPS(LOGITEM_DATAPROPS)
    DECLARE_DATAPROPS(LogItem, LogItemData)

public:
    bool isNull(void) const;
    QVariant value(const int index) const;
    QVariantList values(void) const;
    void setValue(const int index,
                  const QVariant & var);
    QString toString(void) const;
    void setLevelToPass(void);


private:
    QVariantList mVariantList;
};

#endif // LOGITEM_H
