//
// Created by Ruiguo Yang on 2026/6/4.
//

#include "DailyTemperatures.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> DailyTemperatures::dailyTemperatures(std::vector<int> &temperatures) {
        int n = temperatures.size();
        std::vector<int> ans(n, 0);
        std::vector<std::pair<int, int>> istack;
        for (int i = n - 1; i >= 0; i--) {
            while (!istack.empty() && temperatures[i] >= istack.back().first) {
                istack.pop_back();
            }

            if (!istack.empty()) {
                ans[i] = istack.back().second - i;
            }

            istack.push_back(std::make_pair(temperatures[i], i));
        }
        return ans;
    }

    void DailyTemperatures::test() {
        std::vector<std::vector<int>> temperatures {
            {73,74,75,71,69,72,76,73},
            {30,40,50,60},
            {30,60,90}
        };
        std::vector<std::vector<int>> expect {
            {1,1,4,2,1,1,0,0},
            {1,1,1,0},
            {1,1,0}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = dailyTemperatures(temperatures[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("739", leetcode::DailyTemperatures);