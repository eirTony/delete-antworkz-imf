#ifndef QQLIST_H
#define QQLIST_H

#include <QList>

template <class T> class QQList : public QList<T>
{
public:
    QQList(void) {}
    QQList(const QList<T> tList) : QList<T>(tList) {}
};

#endif // QQLIST_H
