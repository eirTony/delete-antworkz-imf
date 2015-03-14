#ifndef TYPELIB_H
#define TYPELIB_H
#include "type_global.h"

#include <base/ModuleInfo.h>
#include <core/Singleton.h>

/*! @class TypeLib
 *
 * @brief The TypeLib class is the base class for the eirType library.
 */
class TYPESHARED_EXPORT TypeLib : public ModuleInfo
{
public:
    TypeLib(void);
    //static TypeLib * instance(void);
    //virtual void executeUnitTest(void);
};

/*! @typedef Type
 *
 * @brief Is the StaticSingleton instance of TypeLib
 */
typedef StaticSingleton<TypeLib> Type;

#endif // TYPELIB_H
