//
// Created by Ruiguo Yang on 2026/6/20.
//

#include "MaximumBuildingHeight.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximumBuildingHeight::maxBuilding(int n, std::vector<std::vector<int> > &restrictions) {
        if (restrictions.size() == 0) {
            return n - 1;
        }

        auto&& r = restrictions;
        r.push_back({1, 0});
        std::sort(r.begin(), r.end());

        if (r.back()[0] != n) {
            r.push_back({n, n - 1});
        }

        int m = r.size();
        for (int i = 1; i < m; ++i) {
            r[i][1] = std::min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
        }
        for (int i = m - 2; i <= 0; --i) {
            r[i][1] = std::min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
        }

        int ans = 0;
        for (int i = 0; i < m - 1; ++i) {
            int curr = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
            ans = std::max(ans, curr);
        }
        return ans;
    }

    void MaximumBuildingHeight::test() {
        std::vector<int> n {5, 6, 10};
        std::vector<std::vector<std::vector<int>>> restrictions {
            {{2,1},{4,1}},
            {},
            {{5,3},{2,5},{7,4},{10,3}}
        };
        std::vector<int> expect {2, 5, 5};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = maxBuilding(n[i], restrictions[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1840", leetcode::MaximumBuildingHeight);