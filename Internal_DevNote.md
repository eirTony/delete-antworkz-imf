# Introduction #

This developer note details some of the internal structure of the
AntWorkz libraries, classes, and functions.

# BaseLib #

# LogLib #

## Log Macro Types ##

Note: `FUNCTIONINFO` and `FUNCTIONINFO_LINE` are #defined in `base/FunctionInfo.h`.

### Report ###

Handles: Trace, Detail, MoreInfo, Info, Progress
```
void Logger::report(item)
LogItem::ctor(FnInfo, Severity, Message, QVarList)
```

### Dump ###

Handles: DumpVar, DumpHex
```
void Logger::dump(item)
LogItem::ctor(FnInfo, Severity, TBD)
value(0) "%1" QString varName
value(1) "%2" QVariant value
value(2) "%3" int bytes|0
+value(3) "%4" QString typeName
+value(4) "%5" QStringList hexDump
```

### Boolean ###

Handles: Expect, ExpNot, Assert, AssNot, QuitIf?, QuitNot?, Signal, SigNot
_non-bool expected to support ExpectZ(ero) and ExpNotZ(ero)_
```
bool Logger::boolean(item) true if expected
LogItem::ctor(FnInfo, Severity, varName, bool expected, bool actual)
value(0) "%1" QString varName 
value(1) "%2" bool expected
value(2) "%3" (bool?) actual
+value(3) "%4" QString actualTypeName
```

### Compare ###

Handles: UsuallyNE, ExpectEQ, AssertLT, ExpectLE, UsuallyGT, AssertGE
```
bool Logger::compare(item) true if expected
LogItem::ctor(FnInfo, Severity, Relation, expName, expected, actName, actual)
value(0) "%1" QString expName 
value(1) "%2" QVariant expected
value(2) "%3" QString actName
value(3) "%4" QVariant actual
+value(4) "%5" QString actualTypeName
+value(5) "%6" QString expectedTypeName
+value(6) "%7" QString relationName
```

### Pointer ###

Handles: Alloc, Pointer, OPointer
```
bool Logger::pointer(item) true if pass
ctor(FnInfo, Severity, typeName, varName, voidPtr)
value(0) "%1" typeName
value(1) "%2" varName
value(2) "%3" byteCount
value(3) "%4" voidPtr
+value(4) "%5" string voidPtr
```

### Troll ###

Handles: QFatal, QSevere, QWarning, QDebug

TBD

### ToDo ###

Handles: ToDo, NeedDo, MustDo
```
void Logger::todo(item)
LogItem::ctor(FnInfo, Severity, QVariantList=())
value()s from user; appended to message
```