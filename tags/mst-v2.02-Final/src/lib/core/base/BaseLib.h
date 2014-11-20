/*! @file   BaseLib.h   Eclipse BaseLib declaration
 */
#ifndef BASELIB_H
#define BASELIB_H
#include "base_global.h"

#include <QProcessEnvironment>

#include <core/Singleton.h>
#include "ModuleInfo.h"

/*! @class BaseLib
 * @brief The BaseLib is the base class in the eirBase library.
 *
 * The BaseLib contains any classes that would cause a
 * circular dependency in the foundations libraries above.
 *
 */
class BASESHARED_EXPORT BaseLib : public ModuleInfo
{
public:
    BaseLib(void);
//    virtual void executeUnitTest(void);
    QProcessEnvironment systemEnvironment(void) const;
    QString systemEnvironment(const QString & key) const;
    QStringList systemEnvironmentKeys(const QString & startsWith=QString()) const;

private:
    QProcessEnvironment mSystemEnvironment;
};

/*! @typedef Base
 *
 * @brief Is the Singleton instance of BaseLib
 */
typedef Singleton<BaseLib> Base;

#endif // BASELIB_H
