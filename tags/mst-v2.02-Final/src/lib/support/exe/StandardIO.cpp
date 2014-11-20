#include "StandardIO.h"

#include <QFile.h>

StandardIO::StandardIO(QObject * parent)
    : QIODevice(parent)
    , mpInputFile(new QFile(this))
    , mpOutputFile(new QFile(this))
{
    Q_ASSERT(qobject_cast<QFile*>(mpInputFile));
    Q_ASSERT(qobject_cast<QFile*>(mpOutputFile));
}

void StandardIO::close(void)
{
    mpInputFile->close();
    mpOutputFile->close();
}

bool StandardIO::open(OpenMode mode)
{
    bool success = true;
    if (ReadOnly & mode)
        success &= mpInputFile->open(stdin, ReadOnly | Text);
    if (WriteOnly & mode)
        success &= mpOutputFile->open(stdout, WriteOnly | Text);
    return success;
}

qint64 StandardIO::readData(char * data, qint64 maxSize)
{
    return mpInputFile->isReadable()
            ? mpInputFile->read(data, maxSize)
            : 0;
}

qint64 StandardIO::writeData(const char * data, qint64 maxSize)
{
    return mpOutputFile->isWritable()
            ? mpOutputFile->write(data, maxSize)
            : 0;
}
