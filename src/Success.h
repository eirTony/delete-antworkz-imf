#ifndef SUCCESS_H
#define SUCCESS_H

class Success
{
public:
    Success(void);
    Success(const bool yes);
    bool yes(void);
    bool is(void) const;
    bool no(void);
    operator bool (void) const;
    void set(const bool is);

private:
    bool mSuccess = false;
    bool mIsInitialized = false;
};

#endif // SUCCESS_H
