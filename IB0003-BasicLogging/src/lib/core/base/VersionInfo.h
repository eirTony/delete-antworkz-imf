/*! @file   VersionInfo.h   VersionInfo class declarations
*
*/
#ifndef VERSIONINFO_H
#define VERSIONINFO_H
#include "base_global.h"

#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QVector>

#include <type/CProperty.h>

enum BranchType { Other = 0, TaskTopic, PatchHotfix, CustomCustomer, };

typedef QVector<quint16> WordVector;

#define VERSIONINFO_PROPERTIES(TND) \
    TND(int,        Major,          0) \
    TND(int,        Minor,          0) \
    TND(int,        Iteration,      0) \
    TND(int,        Branch,         0) \
    TND(int,        Release,        0) \
    TND(int,        Build,          0) \
    TND(BranchType, BranchType,     Other) \
    TND(QDateTime,  DateTime,       QDateTime()) \
    TND(QString,    String,         QString()) \
    TND(QString,    OrgName,        QString()) \
    TND(QString,    AppName,        QString()) \
    TND(QString,    Copyright,      QString()) \
    TND(QStringList, Legal,         QStringList()) \
    TND(QString,    Company,        QString()) \
    TND(QString,    ModuleName,     QString()) \
    TND(QString,    Descripton,     QString()) \
    TND(QString,    BranchName,     QString()) \
    TND(QString,    BranchInfo,     QString()) \

/*! @class VersionInfo
 *
 * @brief The VersionInfo stores various version and identification items.
 *
 * The typical method to collect version information starts with the
 * CommonVersion.h file that contains company-wide default values.
 * Each library then has a Version.h with values specific to that
 * library. Those files are typically included in the library's base
 * class .cpp file and ModuleInfo::setVersion() is called in that
 * class' c'tor which in turn calls VersionInfo::setAll().
 */
class BASESHARED_EXPORT VersionInfo
{
    DECLARE_PROPERTIES(VERSIONINFO_PROPERTIES);

public:
    VersionInfo(void);
    void setAll(void);

    bool isNull(void) const;
    QString toString(const bool withHex=false) const;
    QString dottedString(void) const;
    WordVector forWindows(void) const;
    quint64 toQWord(void) const;
    void check(quint32 key) const;
};
Q_DECLARE_TYPEINFO(VersionInfo, Q_PRIMITIVE_TYPE);
Q_DECLARE_METATYPE(VersionInfo)

#endif // VERSIONINFO_H
