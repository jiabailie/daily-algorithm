//
// Created by Ruiguo on 19/7/2026.
//

#include "SmallestSubsequenceOfDistinctCharacters.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::string SmallestSubsequenceOfDistinctCharacters::smallestSubsequence(std::string s) {
        std::vector<int> vis(26);
        std::vector<int> num(26);
        for (char ch: s) {
            num[ch - 'a']++;
        }

        std::string stk;
        for (char ch: s) {
            if (!vis[ch - 'a']) {
                while (!stk.empty() && stk.back() > ch) {
                    if (num[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = 0;
                        stk.pop_back();
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                stk.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return stk;
    }

    void SmallestSubsequenceOfDistinctCharacters::test() {
        std::vector<std::string> s {"bcabc", "cbacdcbc"};
        std::vector<std::string> expect {"abc", "acdb"};
        for (int i = 0; i < expect.size(); ++i) {
            std::string actual = smallestSubsequence(s[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1081", leetcode::SmallestSubsequenceOfDistinctCharacters);