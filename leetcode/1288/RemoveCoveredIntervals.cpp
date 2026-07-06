//
// Created by ruiguo on 2026/7/6.
//

#include "RemoveCoveredIntervals.h"

#include <algorithm>
#include <iostream>
#include <ostream>

namespace leetcode {
    int RemoveCoveredIntervals::removeCoveredIntervals(std::vector<std::vector<int> > &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> &a, std::vector<int> &b) {
            return (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]));
        });

        int ans = 0;
        int maxRight = 0;
        for (auto& p: intervals) {
            if (maxRight < p[1]) {
                maxRight = p[1];
                ans++;
            }
        }
        return ans;
    }

    void RemoveCoveredIntervals::test() {
        std::vector<std::vector<std::vector<int>>> intervals {
            {{1,4},{3,6},{2,8}},
            {{1,4},{2,3}}
        };
        std::vector<int> expect {2, 1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = removeCoveredIntervals(intervals[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1288", leetcode::RemoveCoveredIntervals);