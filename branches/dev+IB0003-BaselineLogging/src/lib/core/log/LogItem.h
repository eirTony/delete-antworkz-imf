#ifndef LOGITEM_H
#define LOGITEM_H
#include "LogLib.h"

#include <type/DProperty.h>

#include <QList>
#include <QQueue>

#include <base/BaseLib.h>
#include <base/BasicNameHash.h>
#include <base/FunctionInfo.h>

#include "Severity.h"

#define LOGITEM_DATAPROPS(TND) \
    TND(quint64, ItemKey, 0) \
    TND(qint64, TimeStamp, 0) \
    TND(FunctionInfo, Function, FunctionInfo()) \
    TND(int, Severity, 0) \
    TND(int, Relation, 0) \
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
    enum Relation
    {
        nullRelation=0,
        Data,
        Equal,
        NotEqual,
        LessThan,
        LessEqual,
        MoreThan,
        MoreEqual,
        False,
        True,
        sizeRelation,
        Not=0x8000000,
    };

    DECLARE_PARENT_DATAPROPS(LOGITEM_DATAPROPS)
    DECLARE_DATAPROPS(LogItem, LogItemData)

public:
    LogItem(const Severity severity,
            const QString & typeName,
            const QString & varName,
            const int bytes,
            const VoidPtr voidPtr);
    bool isNull(void) const;
    QVariant value(const int index) const;
    QVariantList values(void) const;
    void setValue(const int index,
                  const QVariant & var);
    QString toString(void) const;
    QString formatted(const BasicName & name);
    void clearFormatted(void);
    void setSeverityToPass(void);
    bool evaluate(const int expectedIndex,
                  const int actualIndex) const;
    bool canConvert(const int expectedIndex,
                    const int actualIndex);
    QString relationName(void) const;

private:
    QVariantList mVariantList;
    BasicNameHash<QString> formattedHash;
};

#endif // LOGITEM_H
