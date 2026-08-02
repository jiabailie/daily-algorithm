//
// Created by Ruiguo on 2/8/2026.
//

#include "CountSubarraysWithEvenOddRatioI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int CountSubarraysWithEvenOddRatioI::countRatioSubarrays(std::vector<int>& nums, int a, int b) {
        int n = nums.size();
        std::vector<int> cntEven(n + 1, 0);
        std::vector<int> cntOdd(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cntEven[i + 1] = cntEven[i];
            cntOdd[i + 1] = cntOdd[i];
            if (nums[i] % 2 == 0) {
                cntEven[i + 1]++;
            } else {
                cntOdd[i + 1]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int x = cntEven[j + 1] - cntEven[i];
                int y = cntOdd[j + 1] - cntOdd[i];

                // x / y <= a / b => x * b - a * y <= 0
                if (y > 0 && x * b - a * y <= 0) {
                    ans++;
                }
            }
        }
        return ans;
    }

    void CountSubarraysWithEvenOddRatioI::test() {
        std::vector<std::vector<int>> nums {
            {1,2,1,2},
            {2,2,1},
            {2,2,2}
        };
        std::vector<int> a {3,2,1};
        std::vector<int> b {2,1,1};
        std::vector<int> expect {7,3,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = countRatioSubarrays(nums[i], a[i], b[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("4011", leetcode::CountSubarraysWithEvenOddRatioI);