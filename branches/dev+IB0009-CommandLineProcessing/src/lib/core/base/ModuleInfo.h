/*! @file ModuleInfo.h Declarations for ModuleInfo class
*
*/
#ifndef MODULE_H
#define MODULE_H
#include "base_global.h"

#include <QMap>
#include <QString>

#include "VersionInfo.h"

/*! @class ModuleInfo
 *
 * @brief The ModuleInfo class manages the overall EIRC library collection.
 *
 */
class BASESHARED_EXPORT ModuleInfo
{
public:
    ModuleInfo(const QString & name=QString());
    bool isNull(void) const;
    void setVersion(void);
    QString name(void) const;
    VersionInfo version(void) const;

public:
    static QStringList moduleNames(void);
    static void debugVersions(void);

private:
    QString mName;
    VersionInfo m_vi;
    static QMap<QString, ModuleInfo *> smName_p_map;
};
Q_DECLARE_TYPEINFO(ModuleInfo, Q_PRIMITIVE_TYPE);

#endif // MODULE_H
