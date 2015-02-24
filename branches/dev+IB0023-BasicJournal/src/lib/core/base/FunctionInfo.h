/*! @file   FunctionInfo.h   BaseLib FunctionInfo class declaration
 */
#ifndef FUNCTIONINFO_H
#define FUNCTIONINFO_H
#include "BaseLib.h"

#include <QFileInfo>
#include <QSharedData>
#include <QString>

#include <type/DProperty.h>

#include "BasicName.h"

struct ArgumentInfo
{
    BasicName Type;
    BasicName Name;
    BasicNameList Attributes;
};

typedef QList<ArgumentInfo> ArgumentList;

#define FUNCTIONINFO_DATAPROPS(TND) \
    TND(QString, PrettyFunction, QString()) \
    TND(QFileInfo, SourceFile, QFileInfo()) \
    TND(ModuleInfo, Module, ModuleInfo()) \
    TND(int, FunctionLine, 0) \
    TND(int, FileLine, 0) \
    TND(BasicName, Namespace, BasicName()) \
    TND(BasicName, ClassName, BasicName()) \
    TND(BasicNameList, Attributes, BasicNameList()) \
    TND(ArgumentList, Arguments, ArgumentList()) \

class FunctionInfoData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(FUNCTIONINFO_DATAPROPS)
public:
    FunctionInfoData(void)
    {
        DEFINE_DATAPROPS_CTORS(FUNCTIONINFO_DATAPROPS)
    }
};

class BASESHARED_EXPORT FunctionInfo
{
public:
    DECLARE_PARENT_DATAPROPS(FUNCTIONINFO_DATAPROPS)
    DECLARE_DATAPROPS(FunctionInfo, FunctionInfoData)
    FunctionInfo(const int fileLine, /* focus on line */
                 const QString & fileName,
                 const QString & prettyFunction);
    FunctionInfo(const QString & prettyFunction,
                 const QString & fileName,
                 const int functionLine /* focus on function */);
    void set(const QString & prettyFunction,
             const QString & fileName,
             const int functionLine,
             const int fileLine);
};

#define FUNCTIONINFO_LINE FunctionInfo(__LINE__, __FILE__, Q_PRETTY_FUNCTION)
#define FUNCTIONINFO FunctionInfo(Q_PRETTY_FUNCTION, __FILE__, __LINE__)

#endif // FUNCTIONINFO_H
