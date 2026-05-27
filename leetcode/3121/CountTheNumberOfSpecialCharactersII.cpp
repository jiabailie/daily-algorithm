//
// Created by Ruiguo Yang on 2026/5/27.
//

#include "CountTheNumberOfSpecialCharactersII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int CountTheNumberOfSpecialCharactersII::numberOfSpecialChars(std::string word) {
        int lower = 0;
        int upper = 0;
        for (int i = 0; i < word.length(); i++) {
            if ('A' <= word[i] && word[i] <= 'Z') {
                int c = 1 << (word[i] - 'A');
                upper |= c;
                continue;
            }

            int c = 1 << (word[i] - 'a');

            // if the correspond upper character appears before
            if (upper & c) {
                if (lower & c) {
                    lower = lower ^ c;
                }
                continue;
            }

            lower |= c;
        }

        int cnt = lower & upper;
        int ans = 0;
        while (cnt) {
            ans++;
            cnt = cnt & (cnt - 1);
        }
        return ans;
    }

    void CountTheNumberOfSpecialCharactersII::test() {
        std::vector<std::string> words {
            "aaAbcBC",
            "abc",
            "AbBCab"
        };
        std::vector<int> expect {3,0,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = numberOfSpecialChars(words[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3121", leetcode::CountTheNumberOfSpecialCharactersII);