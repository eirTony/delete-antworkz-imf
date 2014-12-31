#ifndef QQQUEUE_H
#define QQQUEUE_H

#include <QQueue>

template <class T> class QQQueue : public QQueue<T>
{
public:
    QQQueue(void) {}
    QQQueue(const QQueue<T> tQueue) : QQueue<T>(tQueue) {}
};

#endif // QQQUEUE_H
