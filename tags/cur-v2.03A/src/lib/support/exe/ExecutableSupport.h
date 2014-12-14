#ifndef EXECUTABLESUPPORT_H
#define EXECUTABLESUPPORT_H
#include "ExeLib.h"

#include <QObject>

#include <QFileInfo>
#include <QStringList>
class QApplication;
class QGuiApplication;
class QCoreApplication;


class EXESHARED_EXPORT ExecutableSupport : public QObject
{
    Q_OBJECT
public:
    QCoreApplication * app(void) const;
    const QFileInfo & exeFileInfo(void) const;

protected:
    enum ApplicationClass
    {
        nullApplicationClass = 0,
        Headless,
        Serial,
        Gui,
        Widget,
        sizeApplicationClass
    };

protected:
    explicit ExecutableSupport(ApplicationClass appClass);


signals:
    void quitApp(void);

protected slots:
    void initialize(void);
    void setup(void);
    void start(void);
    void quit(void);

private:
    ApplicationClass mApplicationClass = nullApplicationClass;
    QApplication * mpApplication = 0;
    QGuiApplication * mpGuiApplication = 0;
    QCoreApplication * mpCoreApplication = 0;
    QStringList mRawApplicationArguments;
    QFileInfo mExeFileInfo;

};

#endif // EXECUTABLESUPPORT_H
