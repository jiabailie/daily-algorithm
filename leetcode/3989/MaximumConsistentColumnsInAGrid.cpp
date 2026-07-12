//
// Created by Ruiguo on 12/7/2026.
//

#include "MaximumConsistentColumnsInAGrid.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximumConsistentColumnsInAGrid::maxConsistentColumns(std::vector<std::vector<int>>& grid, int limit) {
        int n = grid[0].size();
        std::vector<int> f(n);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (f[j] <= f[i]) {
                    continue;
                }
                bool ok = true;
                for (const auto& row: grid) {
                    if (std::abs(row[i] - row[j]) > limit) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    f[i] = f[j];
                }
            }
            f[i]++;
            ans = std::max(ans, f[i]);
        }
        return ans;
    }

    void MaximumConsistentColumnsInAGrid::test() {
        std::vector<std::vector<std::vector<int>>> grid {
            {{-2,0,3}},
            {{1,-1,1},{2,2,2}},
            {{-5,5}}
        };
        std::vector<int> limit {2,1,9};
        std::vector<int> expect {2,2,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxConsistentColumns(grid[i], limit[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3989", leetcode::MaximumConsistentColumnsInAGrid);