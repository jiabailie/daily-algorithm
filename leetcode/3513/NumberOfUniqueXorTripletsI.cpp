//
// Created by ruiguo on 2026/7/23.
//

#include "NumberOfUniqueXorTripletsI.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int NumberOfUniqueXorTripletsI::uniqueXorTriplets(std::vector<int> &nums) {
        size_t n = nums.size();
        return n <= 2 ? n : (1 << std::bit_width(n));
    }

    void NumberOfUniqueXorTripletsI::test() {
        std::vector<std::vector<int>> nums {
            {1,2},
            {3,1,2}
        };
        std::vector<int> expect {2,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = uniqueXorTriplets(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3513", leetcode::NumberOfUniqueXorTripletsI);