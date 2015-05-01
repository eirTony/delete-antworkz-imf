#include "Success.h"

Success::Success(void) {;}
Success::Success(const bool yes) : mSuccess(yes) , mIsInitialized(true) {;}

bool Success::yes(void)
{
    mIsInitialized = true;
    return mSuccess = true;
}

bool Success::is(void) const
{
    return mIsInitialized ? mSuccess : false;
}

bool Success::no(void)
{
    mIsInitialized = true;
    return mSuccess = false;
}

Success::operator bool (void) const
{
    return is();
}

void Success::set(const bool is)
{
    mIsInitialized = true;
    mSuccess = is;
}
