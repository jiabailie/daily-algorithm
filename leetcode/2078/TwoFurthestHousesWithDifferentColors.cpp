//
// Created by Ruiguo Yang on 2026/4/20.
//

#include "TwoFurthestHousesWithDifferentColors.h"
#include <algorithm>
#include <iostream>
#include <vector>

namespace leetcode {
    int TwoFurthestHousesWithDifferentColors::maxDistance(std::vector<int> &colors) {
        int n = colors.size();
        int c = colors[0];
        if (c != colors[n - 1]) {
            return n - 1;
        }

        int l = 1;
        while (colors[l] == c) {
            l++;
        }

        int r = n - 2;
        while (colors[r] == c) {
            r--;
        }

        return std::max(n - 1 - l, r);
    }

    void TwoFurthestHousesWithDifferentColors::test() {
        std::vector<std::vector<int>> colors {
            {1,1,1,6,1,1,1},
            {1,8,3,8,3},
            {0,1}
        };
        std::vector<int> expect { 3, 4, 1 };
        for (int i = 0; i < expect.size(); ++i) {
            int actual = maxDistance(colors[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2078", leetcode::TwoFurthestHousesWithDifferentColors);