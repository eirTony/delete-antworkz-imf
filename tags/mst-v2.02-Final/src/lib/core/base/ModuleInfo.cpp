/*! @file ModuleInfo.cpp Definitions for ModuleInfo class
 *
 */
#include "ModuleInfo.h"

#include <QtDebug>
#include <QStringList>

/*! @class ModuleInfo
 *
 * @brief ModuleInfo class stores information about each library.
 *
 * The ModuleInfo also stores pointers to each of its instances
 * that are available within the other libraries or applicaitons.
 */

QMap<QString, ModuleInfo *> ModuleInfo::smName_p_map;

/*! @fn ModuleInfo::ModuleInfo(const QString & name)
 *
 * @brief Collects module info and keeps a pointer to each instance.
 * @param name QString containing the name of the library.
 *
 * Typically the name of library is a defined macro in the myclass_global.h
 * file supplied by QtCreator when a new library skeleton is created.
 */
ModuleInfo::ModuleInfo(const QString & name)
    : mName(name)
{
    smName_p_map.insert(name, this);
}

bool ModuleInfo::isNull(void) const
{
    return mName.isEmpty();
}

/*! @fn void ModuleInfo::setVersion(void)
 *
 * @brief Sets the VersionInfo class data.
 *
 * Typically the Version.h and CommonVersion.h are included in the
 * base class .cpp file that defines the values expected by
 * the VersionInfo::setAll() function.
 *
 * @warning The local Version.h must be included before the
 *      common CommonVersion.h file.
 */
void ModuleInfo::setVersion(void)
{
    m_vi.setAll();
}

/*! @fn QString ModuleInfo::name(void) const
 * @brief ModuleInfo::name returns the name of this library.
 * @return QString name
 *
 *
 */
QString ModuleInfo::name(void) const
{
    return mName;
}

/*!
 * \fn VersionInfo ModuleInfo::version(void) const
 * \brief ModuleInfo::version returns the version information data.
 * \return VersionInfo structure for this library
 */
VersionInfo ModuleInfo::version(void) const
{
    return m_vi;
}

/*! @fn QStringList ModuleInfo::moduleNames(void) // static
 * @brief ModuleInfo::moduleNames
 * @return QStringList module names
 *
 * Returns each of the names of the modules that have
 * been created in this process.
 */
QStringList ModuleInfo::moduleNames(void) // static
{
    return smName_p_map.keys();
}

/*! @fn void ModuleInfo::debugVersions(void) // static
 * @internal
 * @brief ModuleInfo::debugVersions writes to QtDebug for each registered library.
 */
void ModuleInfo::debugVersions(void) // static
{
    foreach (ModuleInfo * p, smName_p_map.values())
        qDebug() << QString("%1 - %2 [%3]")
                    .arg(p->name(), 16)
                    .arg(p->version().toString(false))
                    .arg(p->version().toQWord(), 16, 16);
}
