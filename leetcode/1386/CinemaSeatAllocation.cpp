//
// Created by ruiguo on 2026/8/19.
//

#include "CinemaSeatAllocation.h"

#include <iostream>

namespace leetcode {
    int CinemaSeatAllocation::maxNumberOfFamilies(int n, std::vector<std::vector<int> > &reservedSeats) {
        std::unordered_map<int, int> reserved;
        for (const std::vector<int>& r: reservedSeats) {
            if (2 <= r[1] && r[1] <= 9) {
                reserved[r[0]] |= (1 << (r[1] - 2));
            }
        }

        int emptyRows = n - reserved.size();
        int ans = emptyRows * 2;
        for (const auto [_, x]: reserved) {
            if ((x & 0b1111) == 0 || (x & 0b111100) == 0 || (x & 0b11110000) == 0) {
                ans++;
            }
        }
        return ans;
    }

    void CinemaSeatAllocation::test() {
        std::vector<int> n {3,2,4};
        std::vector<std::vector<std::vector<int>>> reservedSeats {
            {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}},
            {{2,1},{1,8},{2,6}},
            {{4,3},{1,4},{4,6},{1,7}}
        };
        std::vector<int> expect {4,2,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxNumberOfFamilies(n[i], reservedSeats[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("1386", leetcode::CinemaSeatAllocation);