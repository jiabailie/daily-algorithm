//
// Created by Ruiguo Yang on 2026/4/24.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include "FurthestPointFromOrigin.h"

namespace leetcode {
    int FurthestPointFromOrigin::furthestDistanceFromOrigin(std::string& moves) {
        int n = moves.size();
        int cntR = 0;
        int cntL = 0;
        for (char c: moves) {
            if (c == 'R') {
                cntR++;
            } else {
                cntL++;
            }
        }
        return std::abs(cntR - cntL) + (n - cntR - cntL);
    }

    void FurthestPointFromOrigin::test() {
        std::vector<std::string> moves {
            "L_RL__R",
            "_R__LL_",
            "_______"
        };
        std::vector<int> expect { 3,5,7 };

        for (int i = 0; i < expect.size(); i++) {
            int actual = furthestDistanceFromOrigin(moves[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2833", leetcode::FurthestPointFromOrigin);