#ifndef ITEMFORMATBEHAVIOR_H
#define ITEMFORMATBEHAVIOR_H

#include <QHash>

#include <base/BasicName.h>
#include <type/CharCode.h>

#include "LogItem.h"

class ItemFormatBehavior
{
public:
    ItemFormatBehavior(void) {}
    virtual ~ItemFormatBehavior() {}

public: // virtual
    virtual QString formatItem(const BasicName & formatName,
                               const LogItem item);

public: // static
    static ItemFormatBehavior * forFormat(const BasicName & formatName);

protected:
    ItemFormatBehavior(const BasicNameList & formatNames,
                       const BasicName & metaName);


protected: // static
    static void RegisterFormats(const BasicNameList & formatNames,
                                const BasicName & metaName);

private:
    BasicNameList mFormatName;
    EightCCList mFormatEcc;
    QString mErrorString;

private: // static
    static QHash<EightCC, ItemFormatBehavior *> smEccBehaviorHash;
};

#endif // ITEMFORMATBEHAVIOR_H
