//
// Created by ruiguo on 2026/8/27.
//

#include "LexicographicallySmallestPermutationGreaterThanTarget.h"

#include <iostream>

namespace leetcode {
    std::string LexicographicallySmallestPermutationGreaterThanTarget::lexGreaterPermutation(std::string s, std::string target) {
        int left[26]{};
        for (int i = 0; i < s.size(); ++i) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            int b = target[i] - 'a';
            left[b]++;

            bool ok = true;
            for (int c: left) {
                if (c < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok) { continue; }

            for (int j = b + 1; j < 26; ++j) {
                if (left[j] == 0) { continue; }

                left[j]--;
                target[i] = 'a' + j;
                target.resize(i + 1);

                for (int k = 0; k < 26; ++k) {
                    target += std::string(left[k], 'a' + k);
                }
                return target;
            }
        }
        return "";
    }

    void LexicographicallySmallestPermutationGreaterThanTarget::test() {
        std::vector<std::string> s {"abc","leet","baba"};
        std::vector<std::string> target {"bba","code","bbaa"};
        std::vector<std::string> expect {"bca","eelt",""};
        for (int i = 0; i < expect.size(); i++) {
            std::string actual = lexGreaterPermutation(s[i], target[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("3720", leetcode::LexicographicallySmallestPermutationGreaterThanTarget);