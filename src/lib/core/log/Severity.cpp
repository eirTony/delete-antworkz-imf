#include "Severity.h"

Severity::Severity(const int iLevel)
    : mLevelInt(iLevel)
{
    if (mLevelInt < nullLevel || mLevelInt > sizeLevel)
        mLevelInt = nullLevel;
}

Severity::operator bool (void) const
{
    return nullLevel != mLevelInt;
}

Severity::operator int (void) const
{
    return mLevelInt;
}

bool Severity::operator == (const Severity other) const
{
    return mLevelInt == other.mLevelInt;
}

bool Severity::operator >  (const Severity other) const
{
    return mLevelInt > other.mLevelInt;
}
