#ifndef PROGRAMOPTIONS_H
#define PROGRAMOPTIONS_H
#include "ExeLib.h"

#include <QChar>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QFileInfo>
#include <QSettings>
#include <QString>
#include <QStringList>

class EXESHARED_EXPORT ProgramOptions
{
public:
    ProgramOptions(const QString & version=QString(),
                   const QString & appName=QString(),
                   const QString & orgName=QString());

    QCommandLineOption addHelpOption(void);
    QCommandLineOption addVersionOption(void);
    QCommandLineOption addOption(const QString & name,
                                 const QString & description=QString(),
                                 const QString & valueName=QString(),
                                 const QString & defaultValue=QString());
    QCommandLineOption addOption(const QStringList & names,
                                 const QString & description=QString(),
                                 const QString & valueName=QString(),
                                 const QString & defaultValue=QString());
    QCommandLineOption addOption(const QChar & singleChar,
                                 const QString & name,
                                 const QString & description=QString(),
                                 const QString & valueName=QString(),
                                 const QString & defaultValue=QString());
    void addPositionalArgument(const QString & name,
                               const QString & description=QString(),
                               const QString & syntax=QString());

    void process(void); // if app ctor
    void process(const QStringList & appArguments); // from coreApp::arguments()

private:
    void processOption(const QString & slashOption);
    void process(const QString & fileName);
    void process(const QFileInfo & fileInfo);
    void process(const QSettings::Scope scope,
                 const QString & arg);
    void process(const QSettings::Scope scope,
                 const QString & orgName,
                 const QString & appName);
    void process(QSettings * settings);
    QString optionName(const QString & arg);

private:
    QCommandLineParser _parser;
    QStringList passThru_qsl;
    QStringList arguments_qsl;
    QStringList posArgName_qsl;
    QList<QCommandLineOption> option_list;
    QCoreApplication * app_p;
    QString orgName_s;
    QString appName_s;
    QString version_s;
};

#endif // PROGRAMOPTIONS_H
