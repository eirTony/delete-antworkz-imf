#include "ProgramOptions.h"

ProgramOptions::ProgramOptions(const QString & version,
                               const QString & appName,
                               const QString & orgName)
    : orgName_s(orgName)
    , appName_s(appName)
    , version_s(version)
{
    if (qApp)
    {
        if (orgName_s.isEmpty())
            orgName_s = qApp->organizationName();
        else
            qApp->setOrganizationName(orgName_s);
        if (appName_s.isEmpty())
            appName_s = qApp->applicationName();
        else
            qApp->setApplicationName(appName_s);
        if (version_s.isEmpty())
            version_s = qApp->applicationVersion();
        else
            qApp->setApplicationVersion(version_s);
    }
}

QCommandLineOption ProgramOptions::addHelpOption(void)
{
    QCommandLineOption option = _parser.addHelpOption();
    option_list.append(option);
    return option;
}

QCommandLineOption ProgramOptions::addVersionOption(void)
{
    QCommandLineOption option = _parser.addVersionOption();
    option_list.append(option);
    return option;
}

QCommandLineOption ProgramOptions::addOption(const QString & name,
                             const QString & description,
                             const QString & valueName,
                             const QString & defaultValue)
{
    QCommandLineOption option(name, description, valueName, defaultValue);
    option_list.append(option);
    return option;
}

QCommandLineOption ProgramOptions::addOption(const QStringList & names,
                             const QString & description,
                             const QString & valueName,
                             const QString & defaultValue)
{
    QCommandLineOption option(names, description, valueName, defaultValue);
    option_list.append(option);
    return option;
}

QCommandLineOption ProgramOptions::addOption(const QChar & singleChar,
                             const QString & name,
                             const QString & description,
                             const QString & valueName,
                             const QString & defaultValue)
{
    QStringList names;
    names << QString(singleChar) << name;
    QCommandLineOption option(names, description, valueName, defaultValue);
    option_list.append(option);
    return option;
}

void ProgramOptions::addPositionalArgument(const QString & name,
                           const QString & description,
                           const QString & syntax)
{
    posArgName_qsl.append(name);
    _parser.addPositionalArgument(name, description, syntax);
}

void ProgramOptions::process(void)
{
    if (app_p) process(app_p->arguments());

}

void ProgramOptions::process(const QStringList & appArguments)
{
    // built in preprocessing
    process(QSettings::SystemScope, orgName_s, QString());
    process(QSettings::SystemScope, orgName_s, appName_s);
    process(QSettings::UserScope,   orgName_s, QString());
    process(QSettings::UserScope,   orgName_s, appName_s);
    process("./" + orgName_s + ".INI");
    process("./" + appName_s + ".INI");

    // process args from the application for files or registry
    foreach(QString arg, appArguments)
    {
        if (arg.startsWith('$')) process(QSettings::SystemScope, arg.mid(1));
        if (arg.startsWith('%')) process(QSettings::UserScope, arg.mid(1));
        if (arg.startsWith('@')) process(arg.mid(1));
        if (arg.startsWith('/')) processOption(arg.mid(1));
    }
}

void ProgramOptions::processOption(const QString & slashOption)
{
    int x = slashOption.indexOf('=');
    if (x > 1)
    {
        arguments_qsl << optionName(slashOption.left(x-1));
        arguments_qsl << slashOption.mid(x+1);
    }
    else
    {
        arguments_qsl << optionName(slashOption);
    }
}

void ProgramOptions::process(const QString & fileName)
{
    process(QFileInfo(fileName));
}

void ProgramOptions::process(const QFileInfo & fileInfo)
{
    if (fileInfo.exists())
    {
        QSettings * settings
                = new QSettings(fileInfo.absoluteFilePath(),
                                QSettings::IniFormat);
        process(settings);
        delete settings;
    }
}

void ProgramOptions::process(const QSettings::Scope scope,
                             const QString & arg)
{
    if (arg.contains('/'))
    {
        QStringList orgApp = arg.split('/');
        orgApp << appName_s;
        process(scope, orgApp[0], orgApp[1]);
    }
    else
    {
        process(scope, orgName_s, arg);
    }
}

void ProgramOptions::process(const QSettings::Scope scope,
                             const QString & orgName,
                             const QString & appName)
{
    QSettings * settings = new QSettings(scope, orgName, appName);
    process(settings);
    delete settings;
}

void ProgramOptions::process(QSettings * settings)
{
    foreach(QString key, settings->allKeys())
    {
        arguments_qsl << optionName(key);
        QString value = settings->value(key).toString().simplified();
        if ( ! value.isEmpty()) arguments_qsl << value;
    }
}

QString ProgramOptions::optionName(const QString & arg)
{
    QString rtn = "--"+arg;
    return rtn.remove('/');
}
