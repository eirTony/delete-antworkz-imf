/*! @file   FileLinePair.h   BaseLib FileLinePair class declaration
 */
#ifndef FILELINE_H
#define FILELINE_H
#include "BaseLib.h"

#include <QFileInfo>
#include <QPair>

class BASESHARED_EXPORT FileLinePair
        : public QPair<QFileInfo, int>
{
public:
    typedef QPair<QFileInfo, int> Base;
    typedef QSet<FileLinePair> Set;

public:
    FileLinePair(void);
    FileLinePair(const QFileInfo & fi,
                 const int line);
    FileLinePair(const QString & fileName,
                 const int line);
    bool isNull() const;
    QFileInfo fileInfo(void) const;
    QString fileName(void) const;
    int fileLine(void) const;

private:
    QFileInfo mFileInfo;
    int mFileLine = 0;
};

#define FILELINEPAIR FileLinePair(__FILE__, __LINE__)

#endif // FILELINE_H
