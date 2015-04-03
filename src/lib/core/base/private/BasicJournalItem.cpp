#include "BasicJournalItem.h"

BasicJournalItem::BasicJournalItem(const BasicName & name,
                                   const QVariant & var)
    : QPair<BasicName, QVariant>(name, var)
{
}
