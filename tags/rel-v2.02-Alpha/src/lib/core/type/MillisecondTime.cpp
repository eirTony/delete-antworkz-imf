#include "MillisecondTime.h"

#include <stdint.h>

const QDateTime MillisecondTime::base_dt(QDateTime::currentDateTime());
const MillisecondTime  MillisecondTime::base_mst(base_dt);
const MillisecondTime MillisecondTime::tz_msd(base_dt.toUTC()
                                              .toMSecsSinceEpoch() - base_mst);
const MillisecondTime MillisecondTime::null_mst(-1);
const qint64 MillisecondTime::minute_ms = 60 * 1000;
const qint64 MillisecondTime::hour_ms = 60 * minute_ms;
const qint64 MillisecondTime::day_ms = 24 * hour_ms;

MillisecondTime::MillisecondTime(void)
    : _ems(null_mst)
{
#if 0
    QUT_FUNCTION();
    QUT_EXPECT(isNull());
    QUT_EXPECT(null().isNull())
    QUT_EXPECT( ! base().isNull());
    QUT_EXPECT( ! isBaseNull());
#endif
}

MillisecondTime::MillisecondTime(qint64 ems)
    : _ems(ems)
{
}

MillisecondTime::MillisecondTime(const QDateTime & dt)
    : _ems(dt.isValid() ? dt.toMSecsSinceEpoch() : null_mst.value())
{
}

MillisecondTime MillisecondTime::current(void)
{
    return MillisecondTime(QDateTime::currentMSecsSinceEpoch());
}

MillisecondTime MillisecondTime::fromIso(const QString & isoDateTime)
{
    return MillisecondTime(QDateTime::fromString(isoDateTime, Qt::ISODate));
}

MillisecondTime MillisecondTime::fromString(const QString & dateTime)
{
    qint64 i64 = dateTime.toLongLong();
    return MillisecondTime((i64 > 3000)
                           ? QDateTime::fromMSecsSinceEpoch(i64)
                           : QDateTime::fromString(dateTime, Qt::ISODate));
}

bool MillisecondTime::isValid(void) const
{
    return toDateTime().isValid();
}

bool MillisecondTime::isNull(void) const
{
    return null_mst == _ems;
}

bool MillisecondTime::isBaseNull(void)
{
    return null_mst == base_mst;
}

bool MillisecondTime::isSystemUtc(void)
{
    return 0 == tz_msd;
}

MillisecondTime::operator qint64(void) const
{
    return _ems;
}

qint64 MillisecondTime::value(void) const
{
    return _ems;
}

MillisecondTime & MillisecondTime::operator += (const MillisecondTime d)
{
    _ems += d;
    return *this;
}

MillisecondTime & MillisecondTime::operator -= (const MillisecondTime d)
{
    _ems -= d;
    return *this;
}

void MillisecondTime::set(const MillisecondTime other)
{
    _ems = other._ems;
}

void MillisecondTime::nullify(void)
{
    _ems = null_mst;
}

MillisecondTime MillisecondTime::base(void)
{
    return base_mst;
}

qint64 MillisecondTime::baseValue(void)
{
    return base_mst;
}

MillisecondTime MillisecondTime::null(void)
{
    return null_mst;
}

MillisecondTime MillisecondTime::delta(MillisecondTime ems) const
{
    return MillisecondTime(ems - _ems);
}

MillisecondTime MillisecondTime::deltaBase(MillisecondTime ems)
{
    return MillisecondTime(ems - base_mst);
}

QDateTime MillisecondTime::toDateTime(void) const
{
    return QDateTime::fromMSecsSinceEpoch(_ems);
}

QString MillisecondTime::toString(const QString & format) const
{
    return toDateTime().toString(format.isEmpty()
                                 ? "yyyy/MM/dd hh:mm:ss.zzz"
                                 : format);
}

QString MillisecondTime::baseString(const QString & format)
{
    return QDateTime::fromMSecsSinceEpoch(base_mst).toString(format);
}
