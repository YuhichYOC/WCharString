/*
 * TestRun.cpp
 *
 *  Created on: 2017/02/12
 *      Author: y
 */

#include "WCharString.h"

#include <fcntl.h>

void Test01() {
    WCharString wc;
    wc = wc.Value("test message 01 \n");
    cout << wc.ToString();
}

void Test02() {
    WCharString wc;
    wc = wc.Value(L"test message 02 あいうえお \n");
    cout << wc.ToString();
}

void Test03() {
    WCharString wc;
    wc = wc.Value("test message 03 \n");
    wc.Append(L"test message 03 かきくけこ \n");
    cout << wc.ToString();
}

void Test04() {
    WCharString wc;
    string value = "test string 04 \n";
    wc = wc.Value(value);
    cout << wc.ToString();
}

void Test05() {
    WCharString wc;
    wc = wc.Value("test message 05 \n");
    string appendValue = "test string 05 \n";
    wc.Append(appendValue);
    cout << wc.ToString();
}

void Test06() {
    WCharString wc;
    wc = wc.Value(L"test message 06 さしすせそ \n");
    string appendValue = "test string 06 \n";
    wc.Append(appendValue);
    cout << wc.ToString();
}

void Test07() {
    WCharString wc;
    wc.Value("test message 07 \n");
    wc.Append(L"test message 07 たちつてと \n");
    string appendValue = "test string 07 \n";
    wc.Append(appendValue);
    cout << wc.ToString();
}

void Test08() {
    WCharString wc;
    int fd = open("/tmp/not_exist_in_this_machine.anyfile", O_RDONLY, 0644);
    if (fd < 0) {
        cout << wc.SysErrMessage() << " \n";
    }
}

int main() {
    Test01();
    Test02();
    Test03();
    Test04();
    Test05();
    Test06();
    Test07();
    Test08();
    return 0;
}
