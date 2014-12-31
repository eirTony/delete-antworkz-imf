#include "QQString.h"


#include "QQRegularExpression.h"

QQString::QQString(void)
{
#if 0
    QUT_FUNCTION();
    QUT_EXPECT(isNull());
    QUT_EXPECTEQ(0, size());

    QUT_CODE(QQString("string"));
    QUT_CODE(QQString("VariableName1",
                      QQRegularExpression::VariableName()));
#endif
}

QQString::QQString(const QString & other)
    : QString(other)
{
#if 0
    QUT_FUNCTION();
    QUT_EXPECTEQ(other.isNull(), isNull());
    QUT_EXPECTEQ(other.size(), size());
    QUT_EXPECTEQ(other, mid(0));
#endif
}

QQString::QQString(const QString & other,
                   const QRegularExpression & allowRx)
    : QString(allowed(other, allowRx))
{
#if 0
    QUT_FUNCTION();
    QUT_EXPECTEQ(other.isNull(), isNull());
#endif
}

QString QQString::allowed(const QQString & other,
                          const QRegularExpression & re)
{
    return other.allowed(re);
}

QString QQString::allowed(const QRegularExpression & re) const
{
    return re.match(mid(0)).captured();
}
