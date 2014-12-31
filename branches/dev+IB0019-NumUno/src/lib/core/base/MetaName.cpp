#include "MetaName.h"

MetaName::MetaName(const QByteArray & name) : QByteArray(name) {}

MetaName::MetaName(const QString & string) : QByteArray(string.toLocal8Bit()) {}

MetaName::MetaName(const char * chars) : QByteArray(chars) {}



