//
// Created by Ruiguo Yang on 2026/6/28.
//

#include "FilterOccupiedIntervals.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<std::vector<int> > FilterOccupiedIntervals::filterOccupiedIntervals(std::vector<std::vector<int> > &intervals, int freeStart, int freeEnd) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return (a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]));
        });

        std::vector<std::vector<int>> merged;
        for (auto& i: intervals) {
            if (merged.size() == 0) {
                merged.push_back(i);
                continue;
            }
            if (merged.back()[1] >= i[0]) {
                merged.back()[1] = std::max(merged.back()[1], i[1]);
                continue;
            }
            if (merged.back()[1] + 1 == i[0]) {
                merged.back()[1] = i[1];
                continue;
            }
            if (merged.back()[1] < i[0]) {
                merged.push_back(i);
            }
        }

        std::vector<std::vector<int>> ans;
        for (auto& i: merged) {
            if (freeStart <= i[0] && i[1] <= freeEnd) {
                continue;
            }
            if (i[1] < freeStart || freeEnd < i[0]) {
                ans.push_back(i);
                continue;
            }
            if (i[0] < freeStart && freeEnd < i[1]) {
                ans.push_back({i[0], freeStart - 1});
                ans.push_back({freeEnd + 1, i[1]});
                continue;
            }
            if (freeStart <= i[0] && freeEnd < i[1]) {
                ans.push_back({freeEnd + 1, i[1]});
                continue;
            }
            if (i[0] < freeStart && i[1] <= freeEnd) {
                ans.push_back({i[0], freeStart - 1});
            }
        }
        return ans;
    }

    void FilterOccupiedIntervals::test() {
        std::vector<std::vector<std::vector<int>>> intervals {
            {{2,6},{4,8},{10,10},{10,12},{14,16}},
            {{1,5},{2,3}}
        };
        std::vector<int> freeStart {7,3};
        std::vector<int> freeEnd {11,8};
        std::vector<std::vector<std::vector<int>>> expect {
            {{2,6},{12,12},{14,16}},
            {{1,2}}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<std::vector<int>> actual = filterOccupiedIntervals(intervals[i], freeStart[i], freeEnd[i]);
            bool isEqual = std::equal(actual.begin(), actual.end(), expect[i].begin(), expect[i].end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3975", leetcode::FilterOccupiedIntervals);