#include "FileLinePair.h"

FileLinePair::FileLinePair(void)
    : QPair<QFileInfo, int>(QFileInfo(), 0) {}
