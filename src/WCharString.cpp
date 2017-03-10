/*
 * WCharString.cpp
 *
 *  Created on: 2017/02/12
 *      Author: y
 */

#include "WCharString.h"

void WCharString::Assign(char * arg) {
    value.assign(arg);
}

void WCharString::Assign(wchar_t * arg) {
    if (arg != nullptr) {
        wstring castedArg = arg;
        size_t argSize = (castedArg.length() + 1) * 2;
        unique_ptr<char> mbArg(new char[argSize]);
        locale::global(locale(""));
        wcstombs(mbArg.get(), arg, argSize);
        locale::global(locale("C"));
        value.assign(mbArg.get());
    }
}

void WCharString::Assign(string arg) {
    value.assign(arg);
}

void WCharString::Assign(string * arg) {
    value.assign(*arg);
}

void WCharString::Assign(const char * arg) {
    value.assign(arg);
}

void WCharString::Assign(const wchar_t * arg) {
    wstring castedArg = arg;
    size_t argSize = (castedArg.length() + 1) * 2;
    unique_ptr<char> mbArg(new char[sizeof(char) * argSize]);
    locale::global(locale(""));
    wcstombs(mbArg.get(), arg, argSize);
    locale::global(locale("C"));
    value.assign(mbArg.get());
}

void WCharString::Assign(const string * arg) {
    value.assign(*arg);
}

WCharString WCharString::Append(char * arg) {
    value.append(arg);
    return *this;
}

WCharString WCharString::Append(wchar_t * arg) {
    wstring castedArg = arg;
    size_t argSize = (castedArg.length() + 1) * 2;
    unique_ptr<char> mbArg(new char[sizeof(char) * argSize]);
    locale::global(locale(""));
    wcstombs(mbArg.get(), arg, argSize);
    locale::global(locale("C"));
    value.append(mbArg.get());
    return *this;
}

WCharString WCharString::Append(string arg) {
    value.append(arg);
    return *this;
}

WCharString WCharString::Append(string * arg) {
    value.append(*arg);
    return *this;
}

WCharString WCharString::Append(const char * arg) {
    value.append(arg);
    return *this;
}

WCharString WCharString::Append(const wchar_t * arg) {
    wstring castedArg = arg;
    size_t argSize = (castedArg.length() + 1) * 2;
    unique_ptr<char> mbArg(new char[sizeof(char) * argSize]);
    locale::global(locale(""));
    wcstombs(mbArg.get(), arg, argSize);
    locale::global(locale("C"));
    value.append(mbArg.get());
    return *this;
}

WCharString WCharString::Append(const string * arg) {
    value.append(*arg);
    return *this;
}

WCharString WCharString::Value(char * arg) {
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(wchar_t * arg) {
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(string arg) {
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(string * arg) {
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(const char * arg) {
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(const wchar_t * arg) {
    Assign(arg);
    return *this;
}

WCharString WCharString::Value(const string * arg) {
    Assign(arg);
    return *this;
}

unique_ptr<wchar_t> WCharString::ToWChar() {
    size_t retSize = value.length() + 1;
    unique_ptr<wchar_t> ret(new wchar_t[retSize]);
    locale::global(locale(""));
    mbstowcs(ret.get(), value.c_str(), retSize);
    locale::global(locale("C"));
    return ret;
}

string WCharString::ToString() {
    return value;
}

bool WCharString::WChar_tStartsWith(wchar_t * arg1eval, string arg2test) {
    wstring castedArg1 = arg1eval;
    if (castedArg1.length() < arg2test.length()) {
        return false;
    }
    for (size_t i = 0; i < arg2test.length(); i++) {
        if (castedArg1.at(i) != arg2test.at(i)) {
            return false;
        }
    }
    return true;
}

string WCharString::SysErrMessage() {
    int index = errno;
    const char * ret = ERROR_0;
    for (int i = 0; i < index; i++) {
        while (ret[0] != '\0') {
            ret++;
        }
        ret++;
    }
    return string(ret);
}

WCharString::WCharString() {
}

WCharString::~WCharString() {
}
