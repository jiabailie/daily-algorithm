//
// Created by Ruiguo Yang on 2026/4/28.
//

#include "MinimumOperationsToMakeUniValueGrid.h"

#include <algorithm>
#include <iostream>

namespace leetcode {
    int MinimumOperationsToMakeUniValueGrid::minOperations(std::vector<std::vector<int> > &grid, int x) {
        std::vector<int> arr;
        int m = grid[0][0] % x;
        for (std::vector<int>& row: grid) {
            for (int v: row) {
                if (v % x != m) {
                    return -1;
                }
                arr.push_back(v);
            }
        }

        std::nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
        int median = arr[arr.size() / 2];

        int sum = 0;
        for (int x: arr) {
            sum += abs(x - median);
        }
        return (sum / x);
    }

    void MinimumOperationsToMakeUniValueGrid::test() {
        std::vector<std::vector<std::vector<int> > > grid {
            {{2,4},{6,8}},
            {{1,5},{2,3}},
            {{1,2},{3,4}}
        };
        std::vector<int> xs {2,1,2};
        std::vector<int> expect {4,5,-1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minOperations(grid[i], xs[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2033", leetcode::MinimumOperationsToMakeUniValueGrid);
