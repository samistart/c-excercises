#include <memory>
#include <sstream>

#ifndef SAMISTRING_H
#define SAMISTRING_H

class SamiString {
private:
    char* internalString;
    std::size_t mLength;
public:
    SamiString();
    SamiString(const char* copyString);
    SamiString(const SamiString& samiString);
    int length() const;
    char operator[](int i) const {internalString[i];}
    char& operator[](int i){return internalString[i];}
    bool operator==(const SamiString& rhs) const;
    bool operator!=(const SamiString& rhs) const {return !(operator==(rhs));}
    bool operator<(const SamiString& rhs) const;
};

#endif //SAMISTRING_H
