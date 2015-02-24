#ifndef TODOITEM_H
#define TODOITEM_H
#include "LogLib.h"


#include <QVariantList>

#include <base/FileLinePair.h>

class TodoItem
{
public:
    typedef QSet<TodoItem> Set;

public:
    TodoItem(void);
    TodoItem(const FileLinePair & fileLine,
             const QVariantList & vars);
    bool operator == (const TodoItem & other) const;
    bool operator  < (const TodoItem & other) const;
    uint hash(const uint key) const;

private:
    QFileInfo mFileInfo;
    int mLineNumber;
    QVariantList mVariants;
};

uint qHash(const TodoItem & todoItem, uint key);

#endif // TODOITEM_H
