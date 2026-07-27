//
// Created by ruiguo on 2026/7/27.
//

#include "SuperPow.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int SuperPow::pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) {
                res = (long)res * x % MOD;
            }
            x = (long)x * x % MOD;
            n /= 2;
        }
        return res;
    }

    int SuperPow::superPow(int a, std::vector<int> &b) {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; i--) {
            ans = (long)ans * pow(a, b[i]);
            a = pow(a, 10);
        }
        return ans;
    }

    void SuperPow::test() {
        std::vector<int> a {2,2,1};
        std::vector<std::vector<int>> b {
            {3},
            {1,0},
            {4,3,3,8,5,2}
        };
        std::vector<int> expect {8,1024,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = superPow(a[i], b[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("372", leetcode::SuperPow);