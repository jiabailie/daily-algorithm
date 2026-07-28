//
// Created by Ruiguo on 28/7/2026.
//

#include "SmallestPalindromicRearrangementI.h"

#include <iostream>

namespace leetcode {
    std::string SmallestPalindromicRearrangementI::smallestPalindrome(std::string s) {
        std::vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c - 'a']++;
        }

        int n = s.size();
        int start = 0;
        int end = n - 1;
        char single = 0;

        std::vector<char> cs(n, 0);
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0) { continue; }
            if (cnt[i] % 2 == 1) {
                single = char('a' + i);
                cnt[i] = cnt[i] - 1;
            }
            for (; cnt[i] > 0; cnt[i] -= 2) {
                cs[start++] = char('a' + i);
                cs[end--] = char('a' + i);
            }
        }

        if (single != 0) {
            cs[start] = single;
        }

        return std::string(cs.begin(), cs.end());
    }

    void SmallestPalindromicRearrangementI::test() {
        std::vector<std::string> s {"z","babab","daccad"};
        std::vector<std::string> expect {"z","abbba","acddca"};
        for (int i = 0; i < expect.size(); ++i) {
            std::string actual = smallestPalindrome(s[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3517", leetcode::SmallestPalindromicRearrangementI);