/*! @file   BaseLib.cpp EclipseIR BaseLib definitions
 */
#include "BaseLib.h"
#include "Version.h"
#include <CommonVersion.h>

#include <QtDebug>

#include "BaseLog.h"

BaseLib * gpBase = &(Base::instance());

/*! @fn BaseLib::BaseLib(void)
 *
 * @brief BaseLib::BaseLib initializes the BaseLib class.
 */
BaseLib::BaseLib(void)
    : ModuleInfo(MODULE_NAME)
    , mSystemEnvironment(QProcessEnvironment::systemEnvironment())
{
    BLOG_MIN(BaseLog::Minimum);
    setVersion();
}

QProcessEnvironment BaseLib::systemEnvironment(void) const
{
    return mSystemEnvironment;
}
QString BaseLib::systemEnvironment(const QString & key) const
{
    return mSystemEnvironment.value(key);
}
QStringList BaseLib::systemEnvironmentKeys(const QString & startsWith) const
{
    QStringList rtn;
    QStringList keyList = mSystemEnvironment.keys();
    if (startsWith.isEmpty())
    {
        rtn = keyList;
    }
    else
    {
        foreach (QString key, keyList)
            if (key.startsWith(startsWith, Qt::CaseInsensitive))
                rtn << key;
    }
    return rtn;
}

#if 0
extern "C" BASESHARED_EXPORT void executeUnitTest(void)
{
    Base::instance()->executeUnitTest();
}

/*! @fn void BaseLib::executeUnitTest(void)
 *
 * @internal
 */
void BaseLib::executeUnitTest(void)
{
    QUT_FUNCTION();
    //QUT_EXPECTEQ(VER_MAJOR, Base::instance()->version().getMajor());
}
#endif
