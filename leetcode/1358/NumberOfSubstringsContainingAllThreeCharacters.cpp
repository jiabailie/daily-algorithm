//
// Created by ruiguo on 2026/6/30.
//

#include "NumberOfSubstringsContainingAllThreeCharacters.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int NumberOfSubstringsContainingAllThreeCharacters::numberOfSubstrings(std::string s) {
        int cnt[3] {0,0,0};
        int ans = 0;
        int left = 0;
        for (char c: s) {
            cnt[c - 'a']++;
            while (cnt[0] && cnt[1] && cnt[2]) {
                cnt[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }
        return ans;
    }

    void NumberOfSubstringsContainingAllThreeCharacters::test() {
        std::vector<std::string> s {"abcabc","aaacb","abc"};
        std::vector<int> expect {10,3,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = numberOfSubstrings(s[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1358", leetcode::NumberOfSubstringsContainingAllThreeCharacters);