//
// Created by Ruiguo Yang on 2026/4/21.
//

#include "MinimizeHammingDistanceAfterSwapOperations.h"
#include "../common/UnionFind.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
    int MinimizeHammingDistanceAfterSwapOperations::minimumHammingDistance(
        std::vector<int>& source,
        std::vector<int>& target,
        std::vector<std::vector<int>>& allowedSwaps) {
        using common::UnionFind;

        int n = source.size();
        UnionFind uf(n);
        for (std::vector<int>& p: allowedSwaps) {
            uf.unite(p[0], p[1]);
        }

        std::unordered_map<int, std::vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            int r = uf.find(i);
            groups[r].push_back(i);
        }

        int ans = 0;
        for (const auto& [_, v]: groups) {
            std::unordered_map<int, int> cnt;
            for (int x: v) {
                cnt[source[x]]++;
                cnt[target[x]]--;
            }

            for (const auto& [_, y]: cnt) {
                ans += abs(y);
            }
        }
        return (ans / 2);
    }

    void MinimizeHammingDistanceAfterSwapOperations::test() {
        std::vector<std::vector<int>> sources {
            {1,2,3,4},
            {1,2,3,4},
            {5,1,2,4,3}
        };
        std::vector<std::vector<int>> targets {
            {2,1,4,5},
            {1,3,2,4},
            {1,5,4,2,3}
        };
        std::vector<std::vector<std::vector<int>>> allowedSwaps {
            {{0,1},{2,3}},
            {},
            {{0,4},{4,2},{1,3},{1,4}}
        };
        std::vector<int> expect { 1, 2, 0 };
        for (int i = 0; i < expect.size(); ++i) {
            int actual = minimumHammingDistance(sources[i], targets[i], allowedSwaps[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1722", leetcode::MinimizeHammingDistanceAfterSwapOperations);
