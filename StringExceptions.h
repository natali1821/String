#pragma once
#include <exception>
#include <stdio.h>
#include "MyString.h"

class MyString;

class StringExceptions : public std::exception {
public:
    StringExceptions(const MyString& s, unsigned int idx);
protected:
    unsigned int _size;
    unsigned int _idx;
};

class AtException : public StringExceptions {
public:
    AtException(const MyString& s, unsigned int idx);
    const char* what() const noexcept override;
};

class EraseException : public StringExceptions {
public:
    EraseException(const MyString& s, unsigned int idx);
    const char* what() const noexcept override;
};

class InsertException : public StringExceptions {
public:
    InsertException(const MyString& s, unsigned int idx);
    const char* what() const noexcept override;
};

class FindException : public StringExceptions {
public:
    FindException(const MyString& s, unsigned int idx);
    const char* what() const noexcept override;
};
