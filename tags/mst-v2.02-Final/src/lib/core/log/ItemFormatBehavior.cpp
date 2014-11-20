#include "ItemFormatBehavior.h"

#include <type/CharCode.h>

ItemFormatBehavior::ItemFormatBehavior(const BasicNameList &formatNames,
                                       const BasicName &metaName)
{
}

QString ItemFormatBehavior::formatItem(const BasicName & formatName,
                                       const LogItem item)
{
    (void)formatName;
    QString format(item.getMessage());
    QVariantList values(item.values());
    int i = 0;
    foreach (QVariant value, values)
    {
        QString percent('%'+QString::number(++i));
        if ( ! format.contains(percent))
            format.append(", " + value.toString());
        else if (format.contains(percent+"!"))
            ; // ignore this one
        else
            format.replace(percent, value.toString());
    }
}
