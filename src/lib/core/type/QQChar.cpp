/*! @file   QQChar.cpp   AntWorkz TypeLib QQChar definition
 */
#include "QQChar.h"

/*! @fn QQChar::QQChar(void)
 * @brief Constructs a null QQChar
 */
QQChar::QQChar(void) {}

/*! @fn QQChar::QQChar(const QChar other)
 * @brief Constructs a QQChar from a QChar
 */
QQChar::QQChar(const QChar other) : QChar(other) {}

/*! @fn QQChar::QQChar(char c)
 * @brief Constructs a QQChar from a Latin1 character
 */
QQChar::QQChar(char c) : QChar(c) {}
