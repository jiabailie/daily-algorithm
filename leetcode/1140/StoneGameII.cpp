//
// Created by Ruiguo on 9/8/2026.
//

#include "StoneGameII.h"

#include <climits>
#include <iostream>

namespace leetcode {
    int StoneGameII::stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        std::vector<std::vector<int>> f(n, std::vector<int>(n + 1));

        int s = 0;
        for (int i = n - 1; i >= 0; --i) {
            s += piles[i];
            for (int m = 1; m <= i / 2 + 1; ++m) {
                if (i + m * 2 >= n) {
                    f[i][m] = s;
                } else {
                    int mn = INT_MAX;
                    for (int x = 1; x <= m * 2; ++x) {
                        mn = std::min(mn, f[i + x][std::max(m, x)]);
                    }
                    f[i][m] = s - mn;
                }
            }
        }
        return f[0][1];
    }

    void StoneGameII::test() {
        std::vector<std::vector<int>> piles {
            {2,7,9,4,4},
            {1,2,3,4,5,100}
        };
        std::vector<int> expect {10, 104};
        for (int i = 0; i < expect.size(); i++) {
            int actual = stoneGameII(piles[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1140", leetcode::StoneGameII);