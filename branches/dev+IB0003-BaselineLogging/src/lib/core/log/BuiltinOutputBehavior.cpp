#include "BuiltinOutputBehavior.h"

#include <base/BasicName.h>
/*
BasicName::List()
                         << BasicName("troll")
                         << BasicName("txtfile")
                         << BasicName("stdout")
                         << BasicName("stderr"),
                         BasicName("BuiltinOutputBehavior")
*/
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
