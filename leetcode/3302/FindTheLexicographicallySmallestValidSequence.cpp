//
// Created by Ruiguo on 8/8/2026.
//

#include "FindTheLexicographicallySmallestValidSequence.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> FindTheLexicographicallySmallestValidSequence::validSequence(std::string s, std::string t) {
        int n = s.size();
        int m = t.size();
        std::vector<int> suffix(n + 1);
        suffix[n] = m;
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            if (j >= 0 && s[i] == t[j]) {
                j--;
            }
            suffix[i] = j + 1;
        }

        std::vector<int> ans(m);
        bool changed = false;
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] == t[j] || !changed && suffix[i + 1] <= j + 1) {
                if (s[i] != t[j]) {
                    changed = true;
                }
                ans[j++] = i;
                if (j == m) {
                    return ans;
                }
            }
        }
        return {};
    }

    void FindTheLexicographicallySmallestValidSequence::test() {
        std::vector<std::string> word1 {
            "vbcca",
            "bacdc",
            "aaaaaa",
            "abc"
        };
        std::vector<std::string> word2 {
            "abc",
            "abc",
            "aaabc",
            "ab"
        };
        std::vector<std::vector<int>> expect {
            {0,1,2},
            {1,2,4},
            {},
            {0,1}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = validSequence(word1[i], word2[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3302", leetcode::FindTheLexicographicallySmallestValidSequence);