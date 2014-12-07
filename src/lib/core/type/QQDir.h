#ifndef QQDIR_H
#define QQDIR_H

#include <QDir>
#include <QList>

class QQDir : public QDir
{
public:
    typedef QList<QQDir> List;

public:
    QQDir(void);
};

#endif // QQDIR_H
