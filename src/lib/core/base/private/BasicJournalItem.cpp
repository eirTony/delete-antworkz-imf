/*! @file   BasicJournalItem.cpp   Eclipse BasicJournalItem definition
 */
#include "BasicJournalItem.h"

BasicJournalItem::BasicJournalItem(const BasicName & name,
                                   const QVariant & var)
    : QPair<BasicName, QVariant>(name, var)
{
}
