//
// Created by Ruiguo Yang on 2026/5/12.
//

#include "MinimumInitialEnergyToFinishTasks.h"

#include <algorithm>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MinimumInitialEnergyToFinishTasks::minimumEffort(std::vector<std::vector<int> > &tasks) {
        std::sort(tasks.begin(), tasks.end(), [](std::vector<int> &a, std::vector<int> &b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        for (auto& t: tasks) {
            std::cout << t[0] << " " << t[1] << std::endl;
        }

        int ans = 0;
        int s = 0;
        for (auto& t: tasks) {
            int acutal = t[0];
            int minimum = t[1];

            ans = std::max(ans, s + minimum);
            s += acutal;
        }
        return ans;
    }

    void MinimumInitialEnergyToFinishTasks::test() {
        std::vector<std::vector<std::vector<int>>> tasks {
            {{1,2},{2,4},{4,8}},
            {{1,3},{2,4},{10,11},{10,12},{8,9}},
            {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}}
        };
        std::vector<int> expect {8,32,27};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minimumEffort(tasks[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1665", leetcode::MinimumInitialEnergyToFinishTasks);
