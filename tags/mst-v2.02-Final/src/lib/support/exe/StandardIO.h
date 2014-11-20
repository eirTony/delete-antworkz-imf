#ifndef STANDARDIO_H
#define STANDARDIO_H
#include "ExeLib.h"

#include <QIODevice>
class QFile;

class EXESHARED_EXPORT StandardIO : public QIODevice
{
    Q_OBJECT
public:
    explicit StandardIO(QObject * parent=0);
    virtual void close(void);
    virtual bool open(OpenMode mode);

protected:
    virtual qint64 readData(char * data, qint64 maxSize);
    virtual qint64 writeData(const char * data, qint64 maxSize);

signals:

public slots:

private:
    QFile * mpInputFile;
    QFile * mpOutputFile;
};

#endif // STANDARDIO_H
