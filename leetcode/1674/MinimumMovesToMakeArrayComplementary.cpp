//
// Created by Ruiguo Yang on 2026/5/13.
//

#include "MinimumMovesToMakeArrayComplementary.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumMovesToMakeArrayComplementary::minMoves(std::vector<int> &nums, int limit) {
        int n = nums.size();
        std::vector<int> diff(limit * 2 + 2);
        for (int i = 0; i < n / 2; ++i) {
            int x = nums[i];
            int y = nums[n - 1 - i];
            int l = std::min(x, y) + 1;
            int r = std::max(x, y) + limit;

            // [2, l - 1] needs change 2 times
            diff[2] += 2;
            diff[l] -= 2;

            // [l, r] doesn't need change
            diff[l]++;
            diff[r + 1]--;

            // (x + y) doesn't need change
            // remove from [l, r]
            diff[x + y]--;
            diff[x + y + 1]++;

            // [r + 1, limit * 2] needs change 2 times
            diff[r + 1] += 2;

            // limit * 2 + 1 is out of [2, limit * 2] so ignore it
        }

        int ans = INT_MAX;
        int sum = 0;
        for (int i = 2; i <= limit * 2; ++i) {
            sum += diff[i];
            ans = std::min(ans, sum);
        }
        return ans;
    }

    void MinimumMovesToMakeArrayComplementary::test() {
        std::vector<std::vector<int>> nums {
            {1,2,4,3},
            {1,2,2,1},
            {1,2,1,2}
        };
        std::vector<int> limits {4,2,2};
        std::vector<int> expect {1,2,0};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minMoves(nums[i], limits[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1674", leetcode::MinimumMovesToMakeArrayComplementary);