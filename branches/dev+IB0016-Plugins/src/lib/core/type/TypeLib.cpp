#include "TypeLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

TypeLib * gpType = &(Type::instance());

TypeLib::TypeLib(void)
    : ModuleInfo(MODULE_NAME)
{
    setVersion();
}

#if 0
extern "C" TYPESHARED_EXPORT void executeUnitTest(void)
{
    Type::instance().executeUnitTest();
}

void TypeLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    //QUT_EXPECTEQ(VER_MAJOR, Type::instance()->version().getMajor());
    QUT_INSTANCE(MillisecondTime);
    QUT_INSTANCE(QQString);
}
#endif
