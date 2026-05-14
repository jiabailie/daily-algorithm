//
// Created by Ruiguo Yang on 2026/5/14.
//

#include "TrappingRainWater.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int TrappingRainWater::trap1(std::vector<int> &height) {
        int n = height.size();

        std::vector<int> leftMax(n, height[0]);
        for (int i = 1; i < n; ++i) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        std::vector<int> rightMax(n, height[n - 1]);
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = std::max(height[i], rightMax[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

    int TrappingRainWater::trap2(std::vector<int> &height) {
        int ans = 0;
        std::vector<int> stk;
        for (int i = 0; i < height.size(); ++i) {
            int h = height[i];
            while (stk.size() > 0 && height[stk.back()] <= h) {
                int bottomH = height[stk.back()];
                stk.pop_back();
                if (stk.size() == 0) {
                    break;
                }
                int left = stk.back();
                int dh = std::min(height[left], height[i]) - bottomH;
                ans += dh * (i - left - 1);
            }
            stk.push_back(i);
        }
        return ans;
    }

    void TrappingRainWater::test() {
        std::vector<std::vector<int>> heights {
            {0,1,0,2,1,0,1,3,2,1,2,1},
            {4,2,0,3,2,5}
        };
        std::vector<int> expect {6,9};

        for (int i = 0; i < expect.size(); i++) {
            int actual = trap1(heights[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }

        for (int i = 0; i < expect.size(); i++) {
            int actual = trap2(heights[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("42", leetcode::TrappingRainWater);