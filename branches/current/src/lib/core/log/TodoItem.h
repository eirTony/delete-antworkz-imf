#ifndef TODOITEM_H
#define TODOITEM_H

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

private:
    QFileInfo mFileInfo;
    int mLineNumber;
    QVariantList mVariants;
};

#endif // TODOITEM_H
