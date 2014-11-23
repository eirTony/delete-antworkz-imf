#include "BuiltinOutputBehavior.h"

#include <base/BasicName.h>

const QByteArray BuiltinOutputBehavior::csmMetaName("BuiltinOutputBehavior");
const EightCC BuiltinOutputBehavior::csmStdout("stdout");
const EightCC BuiltinOutputBehavior::csmStderr("stderr");
const EightCC BuiltinOutputBehavior::csmTxtFile("txtfile");
const EightCC BuiltinOutputBehavior::csmTroll("troll");
const EightCCList BuiltinOutputBehavior::csmRegisteredEccs
                            = EightCCList()     << csmStdout
                                                << csmStderr
                                                << csmTxtFile
                                                << csmTroll;

BuiltinOutputBehavior::BuiltinOutputBehavior(void)
{
}

bool setUrl(const QUrl & url)
{
    if ( ! url.isValid()) return false;

    // DOIT

    return false;
}

bool BuiltinOutputBehavior::open(void)
{
    return false;
}

bool BuiltinOutputBehavior::write(const Severity severity,
                                  const QString & message)
{
    return false;
}

bool BuiltinOutputBehavior::flush(void)
{
    return false;
}

void BuiltinOutputBehavior::close(void)
{

}
