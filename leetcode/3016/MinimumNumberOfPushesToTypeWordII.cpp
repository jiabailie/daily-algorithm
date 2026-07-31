//
// Created by ruiguo on 2026/7/31.
//

#include "MinimumNumberOfPushesToTypeWordII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumNumberOfPushesToTypeWordII::minimumPushes(std::string word) {
        std::vector<int> fac {
            4,4,
            3,3,3,3,3,3,3,3,
            2,2,2,2,2,2,2,2,
            1,1,1,1,1,1,1,1
        };
        std::vector<int> cnt(26, 0);
        for (char c: word) {
            cnt[c - 'a']++;
        }
        std::ranges::sort(cnt.begin(), cnt.end());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += fac[i] * cnt[i];
        }
        return ans;
    }

    void MinimumNumberOfPushesToTypeWordII::test() {
        std::vector<std::string> words {
            "abcde",
            "xyzxyzxyzxyz",
            "aabbccddeeffgghhiiiiii"
        };
        std::vector<int> expect {5,12,24};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minimumPushes(words[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("3016", leetcode::MinimumNumberOfPushesToTypeWordII);