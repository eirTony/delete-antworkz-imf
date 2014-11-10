#ifndef BASICNAMEMAP_H
#define BASICNAMEMAP_H

#include <QMap>
#include "BasicName.h"

template <class T> class BasicNameMap : public QMap<BasicName, T>
{
public:
    BasicNameMap(void) {}
};

#endif // BASICNAMEMAP_H
