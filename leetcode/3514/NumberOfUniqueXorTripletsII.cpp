//
// Created by Ruiguo on 24/7/2026.
//

#include "NumberOfUniqueXorTripletsII.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ostream>

namespace leetcode {
    int NumberOfUniqueXorTripletsII::uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        int maxVal = *std::max_element(nums.begin(), nums.end());
        int u = 1 << std::bit_width(1u * maxVal);

        std::vector<int8_t> has(u);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                has[nums[i] ^ nums[j]] = true;
            }
        }

        std::vector<int8_t> has3(u);
        for (int i = 0; i < u; ++i) {
            if (has[i]) {
                for (int j: nums) {
                    has3[i ^ j] = true;
                }
            }
        }

        return std::reduce(has.begin(), has.end(), 0);
    }

    void NumberOfUniqueXorTripletsII::test() {
        std::vector<std::vector<int>> nums {
            {1,3},
            {6,7,8,9}
        };
        std::vector<int> expect {2,4};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = uniqueXorTriplets(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3514", leetcode::NumberOfUniqueXorTripletsII);
