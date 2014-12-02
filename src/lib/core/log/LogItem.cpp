#include "LogItem.h"

#include <QDateTime>

#include "ItemFormatBehavior.h"
#include "LogLevel.h"

DEFINE_DATAPROPS(LogItem, LogItemData)

void LogItem::ctor(void)
{
    setTimeStamp(QDateTime::currentMSecsSinceEpoch());
}

void LogItem::dtor(void) {}

bool LogItem::isNull(void) const
{
    return !! getLevel();
}

QVariant LogItem::value(const int index) const
{
    return (index >= 0 && index < mVariantList.size())
            ? mVariantList.at(index)
            : QVariant();
}

QVariantList LogItem::values(void) const
{
    return mVariantList;
}

void LogItem::setValue(const int index,
              const QVariant & var)
{
    mVariantList[index] = var;
}

QString LogItem::toString(void) const
{
    static ItemFormatBehavior defaultBehavior;
    return defaultBehavior.formatItem(BasicName(), *this);
}

void LogItem::setLevelToPass(void)
{
}
/*
bool LogItem::evaluate(const int expectedIndex,
                       const int actualIndex) const
{
    QVariant expected = value(expectedIndex);
    QVariant actual = value(actualIndex).convert(expected.type());
    return expected == actual;
}

bool LogItem::canConvert(const int expectedIndex,
                         const int actualIndex)
{
    return value(expectedIndex).canConvert(value(actualIndex).type());
}

QString LogItem::relationName(void) const
{
    return "rel";
}
*/
