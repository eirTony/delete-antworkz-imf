/*! @file BaseLog.h Declarations for BaseLog class
*
*/
#ifndef BASELOG_H
#define BASELOG_H
#include "BaseLib.h"

#define BLOG_MIN(sev)       { BaseLog::setMinimum(sev); }
#define BLOG_FATAL(sev)     { BaseLog::setFatal(sev); }
#define BLOG_SETFILE(fn)    { BaseLog::setFile(fn); }
#define BLOG(sev, fmt, ...) { BaseLog bli(sev, fmt, ##__VA_ARGS__); }

#define BFUNCTION(...)      BLOG(BaseLog::Enter, "%1(%2, %3, %4)", Q_FUNC_INFO, ##__VA_ARGS__)
#define BFNRETURN(var)      BLOG(BaseLog::Leave, "%1 -> %2", Q_FUNC_INFO, var)
#define BALLOC(fmt, ...)    BLOG(BaseLog::Alloc,     fmt, ##__VA_ARGS__)
#define BLOGMSG(fmt, ...)   BLOG(BaseLog::LogMsg,    fmt, ##__VA_ARGS__)
#define BTODO(var)          BLOG(BaseLog::ToDo,   "TODO:   %1 in %4 [%2:%3]", var, __FILE__, __LINE__, Q_FUNC_INFO)
#define BNEEDDO(var)        BLOG(BaseLog::Stern,  "NEEDDO: %1 in %4 [%2:%3]", var, __FILE__, __LINE__, Q_FUNC_INFO)
#define BMUSTDO(var)        BLOG(BaseLog::Assert, "MUSTDO: %1 in %4 [%2:%3]", var, __FILE__, __LINE__, Q_FUNC_INFO)
#define BDETAIL(fmt, ...)   BLOG(BaseLog::Detail,    fmt, ##__VA_ARGS__)
#define BWARNING(fmt, ...)  BLOG(BaseLog::Warning,   fmt, ##__VA_ARGS__)
#define BTRACE(fmt, ...)    BLOG(BaseLog::Trace,     fmt, ##__VA_ARGS__)
#define BMEMORY(fmt, ...)   BLOG(BaseLog::Memory,    fmt, ##__VA_ARGS__)
#define NOBTRACE(fmt, ...)  { (void)fmt; }
#define BDUMPVAR(var)       BLOG(BaseLog::DumpVar, "%1 = {%2}", #var, var)

#define BEXPECTEQ(a, b)     { if (a != b) BLOG(BaseLog::Expect, "EXPECT Failed %1 (%2) not equal %3 (%4)", #a, a, #b, b) }
#define BEXPECTNE(a, b)     { if (a == b) BLOG(BaseLog::Expect, "EXPECT Failed %1 (%2)  is equal %3 (%4)", #a, a, #b, b) }
#define BASSERT(exp)        { if ( ! exp) BLOG(BaseLog::Assert, "%1[%2] Assert Failed: %3", __FILE__, __LINE__, #exp) }
#define BOBJPOINTER(typ, p) { if (0 == qobject_cast<typ *>(p)) BLOG(BaseLog::Pointer, "%1[%2]: %3 is not a %4 QObject pointer", __FILE__, __LINE__, #p, #typ); }
#define BNULPOINTER(p)      { if (0 == p) BLOG(BaseLog::Pointer, "%1[%2]: %3 is not a valid pointer", __FILE__, __LINE__, #p); }

#define BOBJNAME(obj)       ((obj) ? ((obj)->objectName().isEmpty() ? QString((obj)->metaObject()->className()) : (obj)->objectName()) : "{orphan}")
#define BCONNECT(a,b,c,d)   { if ( !    connect(a,b,c,d)) BLOG(BaseLog::Error, "FAILED connect: %s %s %s %s", #a, #b, #c, #d); }
#define BDISCONNECT(a,b,c,d){ if ( ! disconnect(a,b,c,d)) BLOG(BaseLog::Warning, "FAILED disconnect: %s %s %s %s", #a, #b, #c, #d); }
#define BEMIT(exp)          { BLOG(BaseLog::Signal, "emit %1->%2", BOBJNAME(this), #exp); emit exp; }
#define BUSERVAR(var, value) QVariant var; var.setValue(value);

#include <QSharedDataPointer>
#include <QVariant>
class QFile;

void BASESHARED_EXPORT myMsgHandler(QtMsgType t,
                                    const QMessageLogContext & context,
                                    const QString & pc);

/*! @class  BaseLog
 *  @brief  Bare-bone logging facility for early libraries
 *
 *  @note   The static variables minSeverity_i and fatalSeverity_i
 *          are implemented as integer values because the unlying
 *          Enumeration and Named<int> use a QMap<> facility
 *          that can't be used in static initialization.
 *
 *  @todo   BLOG_PUSH() and BLOG_PULL() to stack minimum and fatal severities.
 *
 *  @todo   Determine if we are done with static initialization
 *          and don't instanciate BaseLog in BLOG macro.
 *
 */
class BASESHARED_EXPORT BaseLog
{
public:
    enum Severity
    {
        Minimum,   /* 0*/
        Alloc,     /* 1*/
        Leave,     /* 2*/
        EnterArg,  /* 3*/
        Enter,     /* 4*/
        Signal,    /* 5*/
        Thread,    /* 6*/
        Data,      /* 7*/
        DumpHex,   /* 8*/
        DumpVar,   /* 9*/
        Dump,      /*10*/
        Detail,    /*11*/
        Trace,     /*12*/
        Expect,    /*13*/
        State,     /*14*/
        Info,      /*15*/
        LogMsg,    /*16*/
        Progress,  /*17*/
        ToDo,      /*18*/
        Notice,    /*19*/
        Watch,     /*20*/
        Warning,   /*21*/
        Stern,     /*22*/
        Error,     /*23*/
        Contract,  /*24*/
        Pointer,   /*25*/
        Memory,    /*26*/
        Assert,    /*27*/
        Fatal,     /*28*/
        Kill,      /*29*/
        Shutdown,  /*30*/
        Maximum,   /*31*/
    };

public:
    //BaseLog(void);
    BaseLog(const BaseLog::Severity severity,
            const QString & format,
            const QVariant & value1=QVariant(),
            const QVariant & value2=QVariant(),
            const QVariant & value3=QVariant(),
            const QVariant & value4=QVariant());

public: // static methods
    static void setMinimum(const Severity severity);
    static void setFatal(const Severity severity);
    static Severity minimumSeverity(void);
    static Severity fatalSeverity(void);
    static bool isMinimum(const Severity severity);
    static bool isWarning(const Severity severity);
    static bool isError(const Severity severity);
    static bool isFatal(const Severity severity);
    static QFile * blogFile(void);
    static QString blogFileName(void);
    static void setFile(const QString & fileName=QString());
    static void resetFile(void);
    static QString fillString(const QString & format,
                              const QVariant & value1,
                              const QVariant & value2,
                              const QVariant & value3,
                              const QVariant & value4);
    static void write(const Severity severity,
                      const QString & message);
    static void flush(void);
//  static QUrl url(void);
    static QChar severityChar(const Severity sev);

private: // static members
    static Severity min_sev;
    static Severity fatal_sev;
    static QFile * blog_file;
};


#endif // BASELOG_H
