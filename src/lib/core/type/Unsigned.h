#ifndef UNSIGNED_H
#define UNSIGNED_H

template <class UINT> class Unsigned
{
public:
    Unsigned(void)  : mUnsigned(0) {}
    Unsigned(const UINT u) : mUnsigned(u) {}
    operator UINT (void) const { return mUnsigned; }
    UINT operator() (void) const { return mUnsigned; }

private:
    UINT mUnsigned = 0;
};

typedef Unsigned<quint64> Unsigned64;

#endif // UNSIGNED_H
