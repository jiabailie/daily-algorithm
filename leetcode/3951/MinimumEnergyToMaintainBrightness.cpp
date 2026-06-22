//
// Created by ruiguo on 2026/6/19.
//

#include "MinimumEnergyToMaintainBrightness.h"

#include <iostream>
#include <ostream>
#include <queue>

namespace leetcode {
    std::vector<std::vector<int> > MinimumEnergyToMaintainBrightness::mergeIntervals(std::vector<std::vector<int> > &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]));
        });

        std::vector<std::vector<int>> ans;
        for (auto& i: intervals) {
            if (ans.size() == 0) {
                ans.push_back(i);
                continue;
            }

            if (ans.back()[1] < i[0]) {
                ans.push_back(i);
                continue;
            }

            if (ans.back()[1] == i[0]) {
                ans.back()[1] = i[1];
                continue;
            }

            ans.back()[0] = std::min(ans.back()[0], i[0]);
            ans.back()[1] = std::max(ans.back()[1], i[1]);
        }
        return ans;
    }

    long long MinimumEnergyToMaintainBrightness::minEnergy(int n, int brightness, std::vector<std::vector<int> > &intervals) {
        ll light = (brightness + 2) / 3;
        ll totalTime = 0;
        std::vector<std::vector<int>> merged = mergeIntervals(intervals);
        for (const auto& i: merged) {
            totalTime += i[1] - i[0] + 1;
        }
        return (light * totalTime);
    }

    void MinimumEnergyToMaintainBrightness::test() {
        std::vector<int> n {5,2,4,4};
        std::vector<int> brightness {5,1,2,2};
        std::vector<std::vector<std::vector<int>>> intervals {
            {{6,12}},
            {{0,0},{2,2}},
            {{1,3},{2,4}},
            {{1,3},{2,4},{1,2},{3,5}}
        };
        std::vector<ll> expect {14,2,4,5};
        for (int i = 0; i < expect.size(); i++) {
            ll actual = minEnergy(n[i], brightness[i], intervals[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3951", leetcode::MinimumEnergyToMaintainBrightness);
