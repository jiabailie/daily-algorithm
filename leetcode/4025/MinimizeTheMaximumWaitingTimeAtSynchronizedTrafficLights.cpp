//
// Created by ruiguo on 2026/8/18.
//

#include "MinimizeTheMaximumWaitingTimeAtSynchronizedTrafficLights.h"

#include <algorithm>
#include <iostream>

namespace leetcode {
    int MinimizeTheMaximumWaitingTimeAtSynchronizedTrafficLights::minPenalty(int period, std::vector<int> &lights, std::vector<int> &arrivalTime) {
        int mx = std::ranges::max(lights);
        int ans = 0;
        for (int x: arrivalTime) {
            x %= period;
            if (x >= mx) {
                ans = std::max(ans, period - x);
            }
        }
        return ans;
    }

    void MinimizeTheMaximumWaitingTimeAtSynchronizedTrafficLights::test() {
        std::vector<int> period {8,10,5};
        std::vector<std::vector<int>> lights {{2,3},{3,6,8},{2}};
        std::vector<std::vector<int>> arrivalTime {{2,5,8,11},{4,9,15},{2,3,4,5,6}};
        std::vector<int> expect {5,1,3};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minPenalty(period[i], lights[i], arrivalTime[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("4025", leetcode::MinimizeTheMaximumWaitingTimeAtSynchronizedTrafficLights);