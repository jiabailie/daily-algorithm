//
// Created by Ruiguo Yang on 2026/6/12.
//

#include "CountNumbersWithUniqueDigits.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int CountNumbersWithUniqueDigits::countNumbersWithUniqueDigits(int n) {
        std::vector<int> cnt(9, 0);
        cnt[0] = 1;
        cnt[1] = 9;
        for (int i = 2; i <= n; ++i) {
            cnt[i] = 9;

            int k = 9;
            for (int j = 1; j < i; ++j) {
                cnt[i] *= k;
                k--;
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            ans += cnt[i];
        }
        return ans;
    }

    void CountNumbersWithUniqueDigits::test() {
        std::vector<int> n {2,0,5};
        std::vector<int> expect {91,1,32491};
        for (int i = 0; i < expect.size(); i++) {
            int actual = countNumbersWithUniqueDigits(n[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("357", leetcode::CountNumbersWithUniqueDigits);
