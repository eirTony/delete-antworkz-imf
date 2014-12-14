/*! @file   BaseLib.h   Eclipse BaseLib declaration
 */
#ifndef BASELIB_H
#define BASELIB_H
#include "base_global.h"

/*! @defgroup BaseLib
 *
 * The BaseLib contains any classes that would cause a
 * circular dependency in the foundations libraries above.
 */

#include <QProcessEnvironment>

#include <core/Singleton.h>
#include "ModuleInfo.h"

typedef void * VoidPtr;

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
/*! @class BaseLib BaseLib.h <base/BaseLib.h>
 * @brief The BaseLib is the base class in the eirBase library.
 * @ingroup BaseLib
 * @since BaseLib was started in v2.02
 * @remark { Note: As with all library class files,
 * BaseLib is implemented as a singleton
 * and is used to provide static constructors
 * needed for its classes. }
 */

typedef Singleton<BaseLib> Base;
/*! @typedef Base
 *
 * @brief Is the Singleton instance of BaseLib
 */

#endif // BASELIB_H
