//
// Created by Ruiguo on 5/8/2026.
//

#include "RemoveMethodsFromProject.h"

#include <iostream>
#include <numeric>
#include <ostream>

namespace leetcode {
    std::vector<int> RemoveMethodsFromProject::remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        std::vector<std::vector<int>> g(n, std::vector<int>());
        for (auto& e: invocations) {
            g[e[0]].push_back(e[1]);
        }

        std::vector<bool> isSuspicious(n, false);
        auto dfs = [&](auto&& dfs, int x) -> void {
            isSuspicious[x] = true;
            for (int y: g[x]) {
                if (!isSuspicious[y]) {
                    dfs(dfs, y);
                }
            }
        };
        dfs(dfs, k);

        for (auto& e: invocations) {
            if (!isSuspicious[e[0]] && isSuspicious[e[1]]) {
                std::vector<int> ans(n);
                std::iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!isSuspicious[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    void RemoveMethodsFromProject::test() {
        std::vector<int> n {4,5,3};
        std::vector<int> k {1,0,2};
        std::vector<std::vector<std::vector<int>>> invocations {
            {{1,2},{0,1},{3,2}},
            {{1,2},{0,2},{0,1},{3,4}},
            {{1,2},{0,1},{2,0}}
        };
        std::vector<std::vector<int>> expect {
            {0,1,2,3},
            {3,4},
            {}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = remainingMethods(n[i], k[i], invocations[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3310", leetcode::RemoveMethodsFromProject);