//
// Created by Ruiguo Yang on 2026/6/21.
//

#include "MaximumTotalValue.h"

#include <algorithm>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximumTotalValue::maxTotalValue(std::vector<int> &value, std::vector<int> &decay, int m) {
        auto check = [&](int low) -> bool {
            int leftM = m;
            for (int i = 0; i < value.size(); i++) {
                int v = value[i];
                if (v >= low) {
                    leftM -= (v - low) / decay[i] + 1;
                    if (leftM < 0) {
                        return true;
                    }
                }
            }
            return false;
        };

        int left = 0;
        int right = *std::max_element(value.begin(), value.end()) + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int low = left;

        long long ans = 0;
        for (int i = 0; i < value.size(); i++) {
            int v = value[i];
            if (v > low) {
                int d = decay[i];
                int k = (v - low - 1) / d + 1;
                m -= k;
                ans += (v * 2 - 1LL * d * (k - 1)) * k;
            }
        }

        ans /= 2;
        ans += 1LL * m * low;
        return (ans % 1'000'000'007);
    }

    void MaximumTotalValue::test() {
        std::vector<std::vector<int>> value {
            {6,5,4},
            {7,2,2},
            {4,3}
        };
        std::vector<std::vector<int>> decay {
            {2,1,1},
            {3,2,1},
            {5,4}
        };
        std::vector<int> m {4,2,5};
        std::vector<int> expect {19,11,7};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxTotalValue(value[i], decay[i], m[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3971", leetcode::MaximumTotalValue);