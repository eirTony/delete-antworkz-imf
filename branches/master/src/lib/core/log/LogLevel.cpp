#include "LogLevel.h"

LogLevel::LogLevel(const int iLevel)
    : mLevelInt(iLevel)
{
    if (mLevelInt < nullLevel || mLevelInt > sizeLevel)
        mLevelInt = nullLevel;
}

LogLevel::operator bool (void) const
{
    return nullLevel != mLevelInt;
}

LogLevel::operator int (void) const
{
    return mLevelInt;
}

bool LogLevel::operator == (const LogLevel other) const
{
    return mLevelInt == other.mLevelInt;
}

bool LogLevel::operator >  (const LogLevel other) const
{
    return mLevelInt > other.mLevelInt;
}
