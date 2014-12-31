/** @file CharCode.h Declarations for CharCode template
  *
  */

#ifndef CHARCODE_HH
#define CHARCODE_HH

#include <QtEndian>
#include <QString>

/** @class  CharCode
  * @brief  Template class for FourCC and EightCC
  * @tparam UINT    basic unsigned integer type with fixed number of bits
  */
template <class UINT> class CharCode
{
public:
    typedef UINT Uint;

public:
    /** @fn     CharCode(void)
      * @brief  constructs a null character code
      */
    CharCode(void) : u(0) {}

    /** @fn     CharCode(const char * c)
      * @brief  constructs a character code with the provided characters
      *
      * If less characters are specified than are available in the
      * unsigned representation, the remaining space is padded with
      * zero bytes.
      *
      * @todo   Do we want to pad with spaces?
      * @todo   Support for big endian
      */
    CharCode(const char * c) : u(c ? *(UINT *)c : 0)
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    { if (c && sizeof(UINT) > ::strlen(c)) u &= (~(UINT)0) >> (8 * (sizeof(UINT) - ::strlen(c))); }
#else
#warning Need to support Q_BIG_ENDIAN
#endif
    CharCode(const QString & s) : u(0) { set(s); }
    /** @fn     CharCode(const TCC & other)
      * @brief  copy constructor
      */
    CharCode(const CharCode & other) : u(other.u) {}

    void set(const QString & s) { const char * c = qPrintable(s); u = *(UINT *)c; }
    /** @fn     isNull(void) const
      * @brief  returns /ret true if character code is null
      */
    bool isNull(void) const { return 0 == u; }

    /** @fn     network(void) const
      * @brief  returns unsigned integer in "network" order
      *
      * This function returns an approrpiate sized unsigned integer
      * in big-endian order where the "first" character code
      * is also "first" in the hex representation of the integer.
      * That is TCC("ABCD").network() == 0x41424344 .
      */
    UINT network(void) const { return qToBigEndian(u); }

    bool operator == (const CharCode & other) const { return u == other.u; }
    bool operator != (const CharCode & other) const { return u != other.u; }
    bool operator <  (const CharCode & other) const
    { return network() <  other.network(); }

    operator const UINT (void) const { return u; }
    UINT operator () (void) const { return u; }

    /** @fn     operator QString(void) const
      * @brief  returns character code's characters as a QString
      */
    operator QString (void) const
    {
        char c[sizeof(UINT) + 1];
        c[sizeof(UINT)] = 0;
        UINT * p = (UINT *)c;
        *p = u;
        return QString(c);
    }

private:
    UINT u;
};

/*! @class  FourCC
  * @brief  A DWORD interpreted as a four character code.
  * @see    class CharCode - template class declaration for details
  */
typedef CharCode<quint32> FourCC;
typedef QList<FourCC> FourCCList;
Q_DECLARE_TYPEINFO(FourCC, Q_PRIMITIVE_TYPE);
Q_DECLARE_TYPEINFO(FourCCList, Q_MOVABLE_TYPE);

/*! @class  EightCC
  * @brief  A QWORD interpreted as an eight character code.
  * @see    class CharCode - template class declaration for details
  */
typedef CharCode<quint64> EightCC;
typedef QList<EightCC> EightCCList;
Q_DECLARE_TYPEINFO(EightCC, Q_PRIMITIVE_TYPE);
Q_DECLARE_TYPEINFO(EightCCList, Q_MOVABLE_TYPE);

#endif // CHARCODE_HH
