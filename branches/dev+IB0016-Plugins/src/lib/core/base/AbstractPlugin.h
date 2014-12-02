#ifndef ABSTRACTPLUGIN_H
#define ABSTRACTPLUGIN_H
#include "BaseLib.h"

#include "ModuleInfo.h"

#include "BasicName.h"

class BasicId;

class BASESHARED_EXPORT AbstractPlugin : public ModuleInfo
{
public:

protected:
    AbstractPlugin(const BasicId & prefix,
                   const BasicName & name,
                   const BasicNameList & aliases);
};

#endif // ABSTRACTPLUGIN_H
