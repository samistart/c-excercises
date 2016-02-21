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
    internalString = new char[mLength + 1];
    memset(internalString, 0, mLength + 1);
    memcpy(internalString, copyString, mLength);
}

SamiString::SamiString(const SamiString &samiString)
{
    mLength = samiString.length();
    internalString = new char[mLength + 1];
    memset(internalString, 0, mLength + 1);
    memcpy(internalString, samiString.internalString, mLength);
}

int SamiString::length() const
{
    return this->mLength;
}

bool SamiString::operator==(const SamiString& rhs) const
{
    if(this->length() != rhs.length())
    {
        return false;
    }
    for(int i = 0; i < this->length(); i++)
    {
        if(this->internalString[i] != rhs.internalString[i])
        {
            return false;
        }
    }
    return true;
}

bool SamiString::operator <(const SamiString& rhs) const
{
    bool thisShorter = this->length() < rhs.length();
    int shortestLength = thisShorter ? this->length() : rhs.length();
    for(int i = 0; i < shortestLength; ++i)
    {
        if (this->internalString[i] != rhs.internalString[i])
        {
            return this->internalString[i] < rhs.internalString[i];
        }
    }
    return thisShorter;
}
