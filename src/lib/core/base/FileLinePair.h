/*! @file   FileLinePair.h   BaseLib FileLinePair class declaration
 */
#ifndef FILELINE_H
#define FILELINE_H

#include <QFileInfo>
#include <QPair>

class FileLinePair : public QPair<QFileInfo, int>
{
public:
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
};

#define FILELINEPAIR FileLinePair(__FILE__, __LINE__)

#endif // FILELINE_H
