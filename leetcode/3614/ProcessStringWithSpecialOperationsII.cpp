//
// Created by ruiguo on 2026/6/17.
//

#include "ProcessStringWithSpecialOperationsII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    char ProcessStringWithSpecialOperationsII::processStr(std::string s, long long k) {
        int n = s.size();
        std::vector<long long> size(n);
        long long sz = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '*') {
                sz = std::max(sz - 1, 0LL);
            } else if (c == '#') {
                sz *= 2;
            } else if (c != '%') {
                sz++;
            }
            size[i] = sz;
        }

        if (k >= size[n - 1]) {
            return '.';
        }

        for (int i = n - 1; ; --i) {
            char c = s[i];
            sz = size[i];
            if (c == '#') {
                if (k >= sz / 2) {
                    k -= sz / 2;
                }
            } else if (c == '%') {
                k = sz - 1 - k;
            } else if (c != '*' && k == sz - 1) {
                return c;
            }
        }
    }

    void ProcessStringWithSpecialOperationsII::test() {
        std::vector<std::string> s {"a#b%*", "cd%#*#","z*#"};
        std::vector<long long> k {1, 3, 0};
        std::vector<char> expect {'a', 'd', '.'};
        for (int i = 0; i < expect.size(); ++i) {
            char actual = processStr(s[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION_IMPL("3614", leetcode::ProcessStringWithSpecialOperationsII);