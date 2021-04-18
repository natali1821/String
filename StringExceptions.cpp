#include "StringExceptions.h"

StringExceptions::StringExceptions(const MyString& s, unsigned int idx) {
    _size = s.size();
    _idx = idx;
}

AtException::AtException(const MyString& s, unsigned int idx) : StringExceptions(s, idx){}

const char* AtException::what() const noexcept{
    char* str = new char[256];
    sprintf(str, "Called at(%d) on string size of %d", _idx, _size);
    return str;
}

EraseException::EraseException(const MyString& s, unsigned int idx) : StringExceptions(s, idx){}

const char* EraseException::what() const noexcept{
    char* str = new char[256];
    sprintf(str, "Called erase(%d) on string size of %d", _idx, _size);
    return str;
}

InsertException::InsertException(const MyString& s, unsigned int idx) : StringExceptions(s, idx){}

const char* InsertException::what() const noexcept{
    char* str = new char[256];
    sprintf(str, "Called insert(%d) on string size of %d", _idx, _size);
    return str;
}

FindException::FindException(const MyString& s, unsigned int idx) : StringExceptions(s, idx){}

const char* FindException::what() const noexcept{
    char* str = new char[256];
    sprintf(str, "Called find(%d) on string size of %d", _idx, _size);
    return str;
}

