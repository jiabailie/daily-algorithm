//
// Created by Ruiguo Yang on 2026/7/5.
//

#include "DivisibleGame.h"

#include <algorithm>
#include <climits>
#include <iostream>

namespace leetcode {
    int DivisibleGame::maxSubArray(std::vector<int> &nums, int k) {
        int ans = INT_MIN;
        int f = 0;
        for (int x: nums) {
            f = std::max(f, 0) + (x % k == 0 ? x : -x);
            ans = std::max(ans, f);
        }
        return ans;
    }

    int DivisibleGame::divisibleGame(std::vector<int> &nums) {
        const int MOD = 1'000'000'007;
        std::vector<int> allPrimeDivisors;
        for (int x: nums) {
            auto& pd = primeDivisors[x];
            allPrimeDivisors.insert(allPrimeDivisors.end(), pd.begin(), pd.end());
        }

        // nums only contains 1
        // Alice must choose some k > 1, thus the smallest possible choice is k = 2.
        // 1 is not divisible by 2, Alice's score is 0, while Bob's score is 1.
        // The score difference is -1.
        if (allPrimeDivisors.empty()) {
            return MOD - 2;
        }

        sort(allPrimeDivisors.begin(), allPrimeDivisors.end());
        allPrimeDivisors.erase(std::unique(allPrimeDivisors.begin(), allPrimeDivisors.end()), allPrimeDivisors.end());

        int maxDiff = INT_MIN;
        int bestK = 0;

        for (int k: allPrimeDivisors) {
            int diff = maxSubArray(nums, k);
            if (diff > maxDiff) {
                maxDiff = diff;
                bestK = k;
            }
        }
        return (1LL * maxDiff * bestK % MOD + MOD) % MOD;
    }

    void DivisibleGame::test() {
        std::vector<std::vector<int>> nums {
            {1,4,6,8},{2,1,2},{1}
        };
        std::vector<int> expect {36,6,1000000005};
        for (int i = 0; i < expect.size(); i++) {
            int actual = divisibleGame(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3984", leetcode::DivisibleGame);