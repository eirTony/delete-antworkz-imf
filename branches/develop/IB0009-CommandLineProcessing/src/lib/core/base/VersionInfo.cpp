#include "VersionInfo.h"

#include <QStringList>


/*! @fn VersionInfo::VersionInfo(void)
 *
 * @brief Initializes its properties with default values.
 */
VersionInfo::VersionInfo(void)
{
    DEFINE_PROPERTIES_CTORS(VERSIONINFO_PROPERTIES);
}

/*! @fn void VersionInfo::setAll(void)
 *
 * @brief Sets all of its properties from the macros.
 */
void VersionInfo::setAll(void)
{
#ifdef VER_STRING
    setString(VER_STRING);
#endif
#ifdef VER_MAJOR
    setMajor(VER_MAJOR);
#endif
#ifdef VER_MINOR
    setMinor(VER_MINOR);
#endif
#ifdef VER_ITERATION
    setIteration(VER_STRING);
#endif
#ifdef VER_BRANCH
    setBranch(VER_BRANCH);
#endif
#ifdef VER_RELEASE
    setRelease(VER_RELEASE);
#endif
#ifdef VER_COPYRIGHT
    setCopyright(VER_COPYRIGHT);
#endif
#ifdef VER_COMPANY
    setCompany(VER_COMPANY);
#endif
#ifdef __MODULE__
    setCompany(__MODULE__);
#endif
#ifdef VER_ORGNAME
    setOrgName(VER_ORGNAME);
#endif
#ifdef VER_APPNAME
    setAppName(VER_APPNAME);
#endif
#ifdef VER_DESCRIPTION
    setDescription(VER_DESCRIPTION);
#endif
#ifdef VER_BRANCHNAME
    setBranchInfo(VER_BRANCHNAME);
#endif
#ifdef VER_BRANCHINFO
    setBranchInfo(VER_BRANCHINFO);
#endif
#ifdef VER_BRANCHTYPE
    setBranchInfo(VER_BRANCHTYPE);
#endif
    setDateTime(QDateTime::fromString(__DATE__ " " __TIME__,
                                      "MMM dd yyyy hh:mm:ss"));
}

/*! @fn bool VersionInfo::isNull(void) const
 *
 * @brief Is true if no major, minor, branch, or release values are set.
 * @return nullness
 */
bool VersionInfo::isNull(void) const
{
    return ! (getMajor() || getMinor() || getBranch() || getRelease());
}

/*! @fn QString VersionInfo::toString(const bool withHex) const
 *
 * @brief Formats its numeric values in human readable form.
 * @param withHex bool include a trailing hexadecimal number
 * @return QString the formatted string.
 */
QString VersionInfo::toString(const bool withHex) const
{
    QString sBranch, sRelease;
    if (getBranch())
        sBranch = QString("+B%1").arg(getBranch(), 2, 10, QChar('0'));
    if (getRelease() > 0 && getRelease() < 27)
        sRelease = QChar(0x40 + getRelease());
    else if (getRelease() >= 0xA0 && getRelease() <= 0xA9)
        sRelease = QString("-Alpha%1").arg(getRelease() - 0xA0);
    else if (getRelease() >= 0xB0 && getRelease() <= 0xB9)
        sRelease = QString("-Beta%1").arg(getRelease() - 0xB0);
    else if (getRelease() >= 0xC0 && getRelease() <= 0xC9)
        sRelease = QString("-RC%1").arg(getRelease() - 0xC0);
    else if (getRelease() >= 0xF1 && getRelease() <= 0xF9)
        sRelease = QString("-Final%1").arg(getRelease() - 0xF0);
    else if (getRelease() != 0xF0 && getRelease() != 0xFF)
        sRelease = QString("-%1").arg(getRelease());
    return withHex
            ? QString("v%1.%2%3%4 [%5]").arg(getMajor())
                                .arg(getMinor(), 2, 10, QChar('0'))
                                .arg(sBranch)
                                .arg(sRelease)
                                .arg(toQWord(), 16, 16, QChar('0'))
            : QString("v%1.%2%3%4").arg(getMajor())
                        .arg(getMinor(), 2, 10, QChar('0'))
                        .arg(sBranch)
                        .arg(sRelease);
}

/*! @fn QString VersionInfo::dottedString(void) const
 *
 * @brief Formats four numbers with dots.
 * @return formatted string
 *
 * The major, minor, branch, and release values are included.
 */
QString VersionInfo::dottedString(void) const
{
    return QString("%1.%2.%3.%4").arg(getMajor()).arg(getMinor())
                                 .arg(getBranch()).arg(getRelease());
}

/*! @fn WordVector VersionInfo::forWindows(void) const
 *
 * @brief Returns four 16-bit words.
 * @return  major-minor, iteration, branch type-version, release
 */
WordVector VersionInfo::forWindows(void) const
{
    WordVector wv(4);
    wv[0] = 1000 * getMajor() + getMinor();
    wv[1] = getIteration();
    wv[2] = 1000 * getBranchType() + getBranch();
    wv[3] = getRelease();
    return wv;
}

/*! @fn quint64 VersionInfo::toQWord(void) const
 *
 * @brief encodes numeric version values
 * @return  encoded unsigned 64-bit integer
 */
quint64 VersionInfo::toQWord(void) const
{
    union
    {
        quint64 qw;
        quint64 major       : 4,
                minor       : 10,
                iteration   : 10,
                release     : 8,
                branchType  : 2,
                branch      : 10,
                build       : 20;
    };

    major       = getMajor();
    minor       = getMinor();
    iteration   = getIteration();
    release     = getRelease();
    branchType  = getBranchType();
    branch      = getBranch();
    build       = getBuild();

    return qw;
}

/*! @fn void VersionInfo::check(quint32 key) const
 *
 * @brief Insures that the copyright message has not been tampered with.
 * @param key an encoding of key copyright characters
 * @warning A fatal exit is taken if tampering has occurred.
 */
void VersionInfo::check(quint32 key) const
{
    QChar c1(0x7F & (key >> 24));
    QChar c2(0x7F & (key >> 16));
    QChar c3(0x7F & (key >>  8));
    QChar c4(0x7F &  key);
    QString s;
    s += c1;
    s += c2;
    s += c3;
    s += c4;
    if (getCopyright().contains(s))
        return;
    qFatal("Nice try");
}
