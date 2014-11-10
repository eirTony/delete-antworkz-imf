#ifndef MILLISECONDS_H
#define MILLISECONDS_H
#include "TypeLib.h"

#include <QDateTime>


/*! @class MillisecondTime
 *
 * @brief The MillisecondTime class manages current or delta dates and times.
 *
 * The MillisecondTime wraps a signed 64-bit integer (minus a few flag bits)
 * that can still represent nearly 100,000 millenia.
 * When used as a current
 * time, the value represents the so-called epoch milliseconds based upon
 * a moment a few days after Linus Torvalds was born (otherwise known at
 * midnight UTC New Years Day 1970).
 * As a delta it represents differences between two different
 * current times.
 *
 * What it doesn't support:
 *  -   Conversion to other calendars, such as Julian.
 *  -   Timezone conversions except between system local and UTC.
 *  -   Daylight savings time aka summer time.
 *  -   Leap seconds
 * Which makes it useful for general computing,
 * but not astronomy or pre-sixteenth century geneology.
 *
 * By default, the current time is collected using the local time of
 * the operating system the process is running on.
 * It also collects the local system time (the Base time) at the time
 * that the process is started--when global static member variables are initialized.
 * At the same time, the difference between system local time and system reported
 * UTC is recorded and can be used in later instances to convert to and from UTC.
 * If the user would like to base all local times in a different to be in a
 * different time zone, the time zone offset can be set manually.
 * Further, the user can specify whether current times are local (or as
 * manually modified) or UTC.
 *
 * A MillisecondTime can be:
 *  -   converted between QDate/QTime/QDateTime.
 *  -   converted to a formatted QString.
 *
 * The parts of a MillisecondTime can be set or extracted separately:
 *  -   milliseconds
 *  -   seconds
 *  -   minutes
 *  -   hours
 *  -   days
 *  -   day of week or month
 *  -   month
 *  -   year
 */
class TYPESHARED_EXPORT MillisecondTime
{
public:
    MillisecondTime(void);
    MillisecondTime(qint64 ems);
    MillisecondTime(const QDateTime & dt);
    bool isNull(void) const;
    bool isValid(void) const;
    operator qint64(void) const;
    qint64 value(void) const;
    MillisecondTime & operator += (const MillisecondTime d);
    MillisecondTime & operator -= (const MillisecondTime d);
    void set(const MillisecondTime other);
    void nullify(void);
    MillisecondTime delta(MillisecondTime ems=current()) const;
    QDateTime toDateTime(void) const;
    QString toString(const QString & format=QString()) const;

public:
    static MillisecondTime base(void);
    static qint64 baseValue(void);
    static MillisecondTime null(void);
    static bool isBaseNull(void);
    static bool isSystemUtc(void);
    static QString baseString(const QString & format=QString());
    static MillisecondTime current(void);
    static MillisecondTime fromIso(const QString & isoDateTime);
    static MillisecondTime fromString(const QString & dateTime);
    static MillisecondTime deltaBase(MillisecondTime ems=current());

private:
    qint64 _ems;
    static const QDateTime base_dt;
    static const MillisecondTime base_mst;
    static const MillisecondTime tz_msd;
    static const MillisecondTime null_mst;
    static const qint64 day_ms;
    static const qint64 hour_ms;
    static const qint64 minute_ms;
};

#endif // MILLISECONDS_H
