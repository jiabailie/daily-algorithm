//
// Created by Ruiguo Yang on 2026/6/6.
//

#include "RemoveDuplicateLetters.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::string RemoveDuplicateLetters::removeDuplicateLetters(std::string s) {
        std::vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c - 'a']++;
        }

        std::string ans;
        std::vector<bool> isUsed(26, false);
        for (char c: s) {
            cnt[c - 'a']--;
            if (isUsed[c - 'a']) {
                continue;
            }

            while (!ans.empty() && c < ans.back() && cnt[ans.back() - 'a']) {
                isUsed[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            isUsed[c - 'a'] = true;
            ans.push_back(c);
        }
        return ans;
    }

    void RemoveDuplicateLetters::test() {
        std::vector<std::string> s {
            "bcabc",
            "cbacdcbc"
        };
        std::vector<std::string> expect {
            "abc",
            "acdb"
        };
        for (int i = 0; i < expect.size(); ++i) {
            std::string actual = removeDuplicateLetters(s[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("316", leetcode::RemoveDuplicateLetters);