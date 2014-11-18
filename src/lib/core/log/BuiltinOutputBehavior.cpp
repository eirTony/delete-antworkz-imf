#include "BuiltinOutputBehavior.h"

#include <base/BasicName.h>

BuiltinOutputBehavior::BuiltinOutputBehavior(const QUrl & url)
    : ForkOutputBehavior(BasicName::List()
                         << BasicName("troll")
                         << BasicName("txtfile")
                         << BasicName("stdout")
                         << BasicName("stderr"),
                         BasicName("BuiltinOutputBehavior"))
{
}

bool setUrl(const QUrl & url)
{

}

bool BuiltinOutputBehavior::open(const QUrl & url)
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
