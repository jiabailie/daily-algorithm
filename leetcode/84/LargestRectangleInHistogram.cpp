//
// Created by Ruiguo Yang on 2026/6/5.
//

#include "LargestRectangleInHistogram.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int LargestRectangleInHistogram::largestRectangleArea(std::vector<int> &heights) {
        int n = heights.size();
        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);

        std::vector<int> istack;
        for (int i = 0; i < n; ++i) {
            while (!istack.empty() && heights[istack.back()] >= heights[i]) {
                istack.pop_back();
            }

            if (!istack.empty()) {
                left[i] = istack.back();
            }
            istack.push_back(i);
        }

        istack.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!istack.empty() && heights[istack.back()] >= heights[i]) {
                istack.pop_back();
            }

            if (!istack.empty()) {
                right[i] = istack.back();
            }
            istack.push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = std::max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }

    void LargestRectangleInHistogram::test() {
        std::vector<std::vector<int>> heights {
            {2,1,5,6,2,3},
            {2,4}
        };
        std::vector<int> expect {10,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = largestRectangleArea(heights[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("84", leetcode::LargestRectangleInHistogram);