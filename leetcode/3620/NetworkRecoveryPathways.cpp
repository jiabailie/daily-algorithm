//
// Created by ruiguo on 2026/7/3.
//

#include "NetworkRecoveryPathways.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int NetworkRecoveryPathways::findMaxPathScore(std::vector<std::vector<int> > &edges, std::vector<bool> &online, long long k) {
        int n = online.size();
        std::vector<std::vector<std::pair<int, int>>> g(n);
        int maxWeight = -1;
        for (auto& e: edges) {
            int x = e[0];
            int y = e[1];
            int weight = e[2];
            if (online[x] && online[y]) {
                g[x].emplace_back(y, weight);
                if (x == 0) {
                    maxWeight = std::max(maxWeight, weight);
                }
            }
        }

        std::vector<long long> memo(n);
        auto check = [&](int lower) -> bool {
            std::fill(memo.begin(), memo.end(), -1);
            auto dfs = [&](auto&& dfs, int x) -> long long {
                if (x == n - 1) {
                    return 0;
                }
                auto& res = memo[x];
                if (res != -1) {
                    return memo[x];
                }
                res = LLONG_MAX / 2;
                for (auto& [y, weight]: g[x]) {
                    if (weight >= lower) {
                        res = std::min(res, dfs(dfs, y) + weight);
                    }
                }
                return res;
            };
            return dfs(dfs, 0) <= k;
        };

        int left = -1;
        int right = maxWeight + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }

    void NetworkRecoveryPathways::test() {
        std::vector<std::vector<std::vector<int>>> edges {
                {{0,1,5},{1,3,10},{0,2,3},{2,3,4}},
                {{0,1,7},{1,4,5},{0,2,6},{2,3,6},{3,4,2},{2,4,6}}
        };
        std::vector<std::vector<bool>> online {
            {true,true,true,true},
            {true,true,true,false,true}
        };
        std::vector<long long> k {10,12};
        std::vector<int> expect {3,6};
        for (int i = 0; i < expect.size(); i++) {
            int actual = findMaxPathScore(edges[i], online[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3620", leetcode::NetworkRecoveryPathways);