//
// Created by Ruiguo on 1/8/2026.
//

#include "PredictTheWinner.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    bool PredictTheWinner::predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> f(n, std::vector<int>(n));

        for (int i = n - 1; i >= 0; --i) {
            f[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = std::max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }
        return (f[0][n - 1] >= 0);
    }

    void PredictTheWinner::test() {
        std::vector<std::vector<int>> nums {
            {1,5,2},
            {1,5,233,7}
        };
        std::vector<bool> expect {false, true};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = predictTheWinner(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("486", leetcode::PredictTheWinner);