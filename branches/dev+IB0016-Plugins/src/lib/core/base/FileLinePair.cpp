/*! @file   FileLinePair.cpp BaseLib FileLinePair class definitions
 */

#include "FileLinePair.h"

FileLinePair::FileLinePair(void)
    : QPair<QFileInfo, int>(QFileInfo(), 0) {}
