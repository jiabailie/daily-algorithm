//
// Created by ruiguo on 2026/7/7.
//

#include "SubsequenceAfterOneReplacement.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    bool SubsequenceAfterOneReplacement::canMakeSubsequence(std::string s, std::string t) {
        int n = s.size();
        int m = t.size();

        std::vector<int> suf(n + 1);
        suf[n] = m;
        int j = m;
        for (int i = n - 1; i >= 0; --i) {
            j--;
            while (j >= 0 && t[j] != s[i]) {
                j--;
            }
            suf[i] = j;
        }

        if (suf[0] >= 0) {
            return true;
        }

        int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (suf[i + 1] - pre > 1) {
                return true;
            }

            pre++;
            while (pre < m && t[pre] != s[i]) {
                pre++;
            }
        }
        return false;
    }

    void SubsequenceAfterOneReplacement::test() {
        std::vector<std::string> ss {"cat","plane"};
        std::vector<std::string> ts {"chat", "apple"};
        std::vector<bool> expect {true, false};
        for (int i = 0; i < expect.size(); ++i) {
            bool actual = canMakeSubsequence(ss[i], ts[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3983", leetcode::SubsequenceAfterOneReplacement);