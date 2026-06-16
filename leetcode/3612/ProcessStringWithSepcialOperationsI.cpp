//
// Created by Ruiguo Yang on 2026/6/16.
//

#include "ProcessStringWithSepcialOperationsI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::string ProcessStringWithSepcialOperationsI::processStr(std::string s) {
        std::string ans;
        for (char c: s) {
            if ('a' <= c && c <= 'z') {
                ans.push_back(c);
                continue;
            }

            if (ans.size() == 0) {
                continue;
            }

            if (c == '*') {
                ans.pop_back();
            } else if (c == '#') {
                ans.append(ans);
            } else if (c == '%') {
                reverse(ans.begin(), ans.end());
            }
        }
        return ans;
    }

    void ProcessStringWithSepcialOperationsI::test() {
        std::vector<std::string> s {
            "a#b%*",
            "z*#"
        };
        std::vector<std::string> expect {
            "ba",
            ""
        };
        for (int i = 0; i < expect.size(); i++) {
            std::string actual = processStr(s[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3612", leetcode::ProcessStringWithSepcialOperationsI);