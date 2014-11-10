#ifndef BASICNAMEHASH_H
#define BASICNAMEHASH_H

#include <QHash>
#include "BasicName.h"

template <class T> class BasicNameHash : public QHash<BasicName, T>
{
public:
    BasicNameHash(void) {}
};

#endif // BASICNAMEHASH_H
