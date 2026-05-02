//
// Created by Ruiguo Yang on 2026/5/2.
//

#include "RotatedDigits.h"
#include <iostream>

namespace leetcode {
    bool RotatedDigits::isValid(int x) {

        std::vector<int> cnt(10, 0);
        while (x) {
            int t = x % 10;
            x /= 10;
            if (t == 3 || t == 4 || t == 7) {
                return false;
            }
            cnt[t]++;
        }
        if (cnt[2] + cnt[5] + cnt[6] + cnt[9] == 0) {
            return false;
        }
        return true;
    }
    int RotatedDigits::rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (isValid(i)) {
                ans++;
            }
        }
        return ans;
    }

    void RotatedDigits::test() {
        std::vector<int> ns {10,1,2};
        std::vector<int> expect {4,0,1};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = rotatedDigits(ns[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("788", leetcode::RotatedDigits);
