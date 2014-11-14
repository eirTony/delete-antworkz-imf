#include "FileLinePair.h"

FileLinePair::FileLinePair(void) {}

FileLinePair::FileLinePair(const QFileInfo & fi,
                           const int line)
    : Base(fi, line) {}

bool FileLinePair::isNull() const
{
    return  ! mFileInfo.isFile() || ! mFileLine;
}

QFileInfo FileLinePair::fileInfo(void) const
{
    return mFileInfo;
}

QString FileLinePair::fileName(void) const
{
    return mFileInfo.absoluteFilePath();
}

int FileLinePair::fileLine(void) const
{
    return mFileLine;
}
