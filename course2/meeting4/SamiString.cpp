#include "SamiString.h"
#include <memory>
#include <iostream>

SamiString::SamiString()
{
    mLength = 0;
}

SamiString::SamiString(const char *copyString)
{
    mLength = strlen(copyString);
    internalString = std::unique_ptr<char[]>(new char[mLength+1]);
    std::strcpy(internalString.get(), copyString);
}

SamiString::SamiString(const SamiString &ss)
{
    mLength = ss.length();
    internalString = std::unique_ptr<char[]>(new char[mLength+1]);
    std::strcpy(internalString.get(), ss.getData());
}

SamiString& SamiString::operator =(const SamiString & rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    mLength = rhs.length();
    internalString.reset(new char[mLength+1]);
    std::strcpy(internalString.get(), rhs.getData());
    return *this;
}


int SamiString::length() const
{
    return this->mLength;
}

bool SamiString::operator==(const SamiString& rhs) const
{
    return (strcmp(internalString.get(), rhs.internalString.get()) == 0);
}

bool SamiString::operator <(const SamiString& rhs) const
{
    return (strcmp(internalString.get(), rhs.internalString.get()) < 0);
}

std::stringstream& operator<<(std::stringstream& ss, SamiString const &samiString)
{
    for(int i = 0; i < samiString.length(); ++i)
    {
        ss.put(samiString[i]);
    }
    return ss;
}


SamiString SamiString::operator+(const SamiString& rhs) const
{   
    SamiString res;
    std::size_t newLength = rhs.length() + this->length();
    res.internalString = std::unique_ptr<char[]>(new char[newLength]);
    std::strcpy(res.internalString.get(), this->getData());
    std::strcat(res.internalString.get(), rhs.getData());
    return res;
}

void SamiString::operator+=(const SamiString& rhs)
{
    const char * tmp = internalString.get();
    mLength += rhs.length();
    internalString.reset(new char[mLength]);
    std::strcpy(internalString.get(), tmp);
    std::strcat(internalString.get(), rhs.getData());
}




