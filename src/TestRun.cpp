/*
 *
 * TestRun.cpp
 *
 * Copyright 2016 Yuichi Yoshii
 *     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
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

void Test09() {
    char testvalue1[10] = "ABCDEFGHI";
    unsigned char testvalue2[10] = "ABCDEFGHI";
    string testvalue3s = "ABCDEFGHI";
    char testvalue3[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        testvalue3[i] = testvalue3s.c_str()[i];
    }
    string testvalue4s = "ABCDEFGHI";
    unsigned char testvalue4[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        testvalue4[i] = testvalue4s.c_str()[i];
    }
    string testvalue5s = "ABCあいう";
    char testvalue5[13] = { 0 };
    for (int i = 0; i < 13; i++) {
        testvalue5[i] = testvalue5s.c_str()[i];
    }
    string testvalue6s = "ABCあいう";
    unsigned char testvalue6[13] = { 0 };
    for (int i = 0; i < 13; i++) {
        testvalue6[i] = testvalue6s.c_str()[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << testvalue1[i] << "\n";
    }
    for (int i = 0; i < 10; i++) {
        cout << testvalue2[i] << "\n";
    }
    for (int i = 0; i < 10; i++) {
        cout << testvalue3[i] << "\n";
    }
    for (int i = 0; i < 10; i++) {
        cout << testvalue4[i] << "\n";
    }
    for (int i = 0; i < 13; i++) {
        cout << testvalue5[i] << "\n";
    }
    for (int i = 0; i < 13; i++) {
        cout << testvalue6[i] << "\n";
    }
    cout << testvalue5 << "\n";
    cout << testvalue6 << "\n";
    char testvalue7[13] = { 0 };
    for (int i = 0; i < 13; i++) {
        testvalue7[i] = testvalue6[i];
    }
    cout << testvalue7 << "\n";
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
    Test09();
    return 0;
}
