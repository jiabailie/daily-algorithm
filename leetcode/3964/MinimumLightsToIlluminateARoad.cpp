//
// Created by ruiguo on 2026/6/23.
//

#include "MinimumLightsToIlluminateARoad.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumLightsToIlluminateARoad::minLights(std::vector<int> &lights) {
        int n = lights.size();
        std::vector<int> diff(n + 1);
        for (int i = 0; i < n; ++i) {
            int v = lights[i];
            if (v > 0) {
                diff[std::max(i - v, 0)]++;
                diff[std::max(i + v + 1, n)]--;
            }
        }

        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diff[i];
            if (sum == 0) {
                ans++;
                sum++;
                diff[std::min(i + 3, n)]--;
            }
        }
        return ans;
    }

    void MinimumLightsToIlluminateARoad::test() {
        std::vector<std::vector<int>> lights {
            {0,0,0,0},
            {0,0,0,2,0}
        };
        std::vector<int> expect {2,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minLights(lights[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3964", leetcode::MinimumLightsToIlluminateARoad);