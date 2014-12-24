#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "CfgLib.h"

#include <var/VariableMap.h>

class CFGSHARED_EXPORT Configuration : public VariableMap
{
public:
    Configuration(void);
};

#endif // CONFIGURATION_H
