#include <memory>
#include <sstream>


#ifndef SAMISTRING_H
#define SAMISTRING_H

class SamiString {
    public:
        SamiString();
        SamiString(const char* copyString);
        SamiString(const SamiString& ss);
        SamiString& operator =(const SamiString & rhs);
        int length() const;
        char operator[](int i) const {return internalString[i];}
        char& operator[](int i){return internalString[i];}
        bool operator==(const SamiString& rhs) const;
        bool operator!=(const SamiString& rhs) const {return !(operator==(rhs));}
        bool operator<(const SamiString& rhs) const;
        friend std::stringstream& operator<<(std::stringstream& ss, const SamiString &samiString);
        const char * getData() const { return internalString.get(); }
        SamiString operator +(const SamiString & rhs) const;
        void operator+=(const SamiString& rhs);

    private:
        std::unique_ptr<char[]> internalString;
        std::size_t mLength;
};

#endif //SAMISTRING_H
