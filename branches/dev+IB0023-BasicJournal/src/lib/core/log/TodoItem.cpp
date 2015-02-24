#include "TodoItem.h"

TodoItem::TodoItem(void) {}

TodoItem::TodoItem(const FileLinePair & fileLine,
                   const QVariantList & vars)
    : mFileInfo(fileLine.fileInfo())
    , mLineNumber(fileLine.fileLine())
    , mVariants(vars) {}

bool TodoItem::operator == (const TodoItem & other) const
{
    return mFileInfo == other.mFileInfo
            && mVariants == other.mVariants;
}

bool TodoItem::operator  < (const TodoItem & other) const
{
    if (mFileInfo != other.mFileInfo)
        return mFileInfo.absoluteFilePath()
                < other.mFileInfo.absoluteFilePath();
    QVariantList varThisList = mVariants;
    QVariantList varThatList = other.mVariants;
    while ( ! varThisList.isEmpty() && ! varThatList.isEmpty())
    {
        QVariant varThis = varThisList.takeFirst();
        QVariant varThat = varThatList.takeFirst();
        if (varThis != varThat) return varThis < varThat;
    }
    return varThisList.size() < varThatList.size();
}

uint TodoItem::hash(const uint key) const
{
    uint hash = qHash(mFileInfo.absoluteFilePath(), key);
    foreach (QVariant var, mVariants)
        hash ^= qHash(var.toString(), key);
    return hash;
}

uint qHash(const TodoItem & todoItem, uint key)
{
    return todoItem.hash(key);
}
