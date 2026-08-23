//
// Created by Ruiguo on 23/8/2026.
//

#include "SumGame.h"

#include <iostream>

namespace leetcode {
    bool SumGame::sumGame(std::string num) {
        int n = num.size();
        int d = 0;
        for (int i = 0; i < n; i++) {
            int x = num[i] == '?' ? 9 : (num[i] - '0') * 2;
            d += i < n / 2 ? x : -x;
        }
        return (d != 0);
    }

    void SumGame::test() {
        std::vector<std::string> num {"5023", "25??", "?3295???"};
        std::vector<bool> expect {false, true, false};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = sumGame(num[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("1927", leetcode::SumGame);