//
// Created by Ruiguo on 26/7/2026.
//

#include "AggregateTwoTimeSeries.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <set>

namespace leetcode {
    std::vector<std::vector<int>> AggregateTwoTimeSeries::aggregateTimeSeries(std::vector<std::vector<int>>& series1, std::vector<std::vector<int>>& series2) {
        std::vector<int> t1;
        std::vector<int> t2;

        std::unordered_map<int, int> tv1;
        std::unordered_map<int, int> tv2;

        std::set<int> t;

        for (const auto& p: series1) {
            t1.push_back(p[0]);
            tv1[p[0]] = p[1];

            t.insert(p[0]);
        }

        for (const auto& p: series2) {
            t2.push_back(p[0]);
            tv2[p[0]] = p[1];

            t.insert(p[0]);
        }

        std::vector<std::vector<int>> ans;
        for (int ti: t) {
            auto it1 = std::lower_bound(t1.begin(), t1.end(), ti);
            auto it2 = std::lower_bound(t2.begin(), t2.end(), ti);

            int v1 = it1 == t1.end() ? 0 : tv1[*it1];
            int v2 = it2 == t2.end() ? 0 : tv2[*it2];
            ans.push_back({ti, v1 + v2});
        }
        return ans;
    }

    void AggregateTwoTimeSeries::test() {
        std::vector<std::vector<std::vector<int>>> series1 {
            {{1,3},{4,1}},
            {{1,5},{3,1}},
            {{1,5}}
        };
        std::vector<std::vector<std::vector<int>>> series2 {
            {{2,2},{5,2}},
            {{2,2}},
            {{1000000000,2}}
        };
        std::vector<std::vector<std::vector<int>>> expect {
            {{1,5},{2,3},{4,3},{5,2}},
            {{1,7},{2,3},{3,1}},
            {{1,7},{1000000000,2}}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<std::vector<int>> actual = aggregateTimeSeries(series1[i], series2[i]);
            bool isEqual = std::equal(actual.begin(), actual.end(), expect[i].begin(), expect[i].end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("4001", leetcode::AggregateTwoTimeSeries);