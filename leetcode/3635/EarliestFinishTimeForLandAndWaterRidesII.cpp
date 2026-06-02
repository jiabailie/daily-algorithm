//
// Created by Ruiguo Yang on 2026/6/2.
//

#include "EarliestFinishTimeForLandAndWaterRidesII.h"

#include <climits>
#include <iostream>

namespace leetcode {
    int EarliestFinishTimeForLandAndWaterRidesII::solve(std::vector<int> &startA, std::vector<int> &durationA, std::vector<int> &startB, std::vector<int> &durationB) {
        int earliestFinishTime = INT_MAX;
        for (int i = 0; i < startA.size(); i++) {
            earliestFinishTime = std::min(earliestFinishTime, startA[i] + durationA[i]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < startB.size(); i++) {
            ans = std::min(ans, std::max(earliestFinishTime, startB[i]) + durationB[i]);
        }
        return ans;
    }

    int EarliestFinishTimeForLandAndWaterRidesII::earliestFinishTime(std::vector<int> &landStartTime, std::vector<int> &landDuration, std::vector<int> &waterStartTime, std::vector<int> &waterDuration) {
        int t1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int t2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return std::min(t1, t2);
    }

    void EarliestFinishTimeForLandAndWaterRidesII::test() {
        std::vector<std::vector<int>> landStartTime {{2,8},{5}};
        std::vector<std::vector<int>> landDuration {{4,1},{3}};
        std::vector<std::vector<int>> waterStartTime {{6},{1}};
        std::vector<std::vector<int>> waterDuration {{3},{10}};
        std::vector<int> expect {9,14};

        for (int i = 0; i < expect.size(); i++) {
            int actual = earliestFinishTime(landStartTime[i], landDuration[i], waterStartTime[i], waterDuration[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3635", leetcode::EarliestFinishTimeForLandAndWaterRidesII);