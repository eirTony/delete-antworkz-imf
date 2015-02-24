/*! @file   QQVariant.cpp   AntWorkz TypeLib QQVariant definition
 */
#include "QQVariant.h"

/*! @fn QQVariant::QQVariant(void)
 * @brief Constructs a null QQVariant
 */
QQVariant::QQVariant(void) {}

/*! @fn QQVariant::QQVariant(char c)
 * @brief Constructs a QQVariant from a QVariant
 */
QQVariant::QQVariant(const QVariant & other) : QVariant(other) {}
