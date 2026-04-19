//
// Created by Ruiguo Yang on 2026/4/19.
//

#include <cstring>
#include <iostream>
#include <vector>
#include "CountGoodIntegersOnAGridPath.h"

namespace leetcode {
    ll CountGoodIntegersOnAGridPath::solve(int pos, bool isTight, int lastPathDigit, const std::string &s) {
        if (pos == 16) {
            return 1;
        }

        if (dp[pos][isTight][lastPathDigit] != -1) {
            return dp[pos][isTight][lastPathDigit];
        }

        ll cnt = 0;
        int limit = isTight ? (s[pos] - '0') : 9;
        for (int i = 0; i <= limit; ++i) {
            bool nextTight = isTight && (i == limit);
            if (isOnPath[pos]) {
                if (i >= lastPathDigit) {
                    cnt += solve(pos + 1, nextTight, i, s);
                }
                continue;
            }
            cnt += solve(pos + 1, nextTight, lastPathDigit, s);
        }
        dp[pos][isTight][lastPathDigit] = cnt;
        return cnt;
    }

    ll CountGoodIntegersOnAGridPath::countGood(ll n) {
        if (n < 0) { return 0; }
        std::string s = std::to_string(n);
        if (s.size() < 16) {
            s = std::string(16 - s.size(), '0') + s;
        }
        std::memset(dp, -1, sizeof(dp));
        return solve(0, true, 0, s);
    }

    long long CountGoodIntegersOnAGridPath::countGoodIntegersOnPath(long long l, long long r, std::string directions) {
        for (int i = 0; i < 16; ++i) {
            isOnPath[i] = false;
        }

        int row = 0;
        int col = 0;
        isOnPath[0] = true;
        for (char c: directions) {
            if (c == 'D') {
                row++;
            } else if (c == 'R') {
                col++;
            }

            isOnPath[row * 4 + col] = true;
        }
        return countGood(r) - countGood(l - 1);
    }

    void CountGoodIntegersOnAGridPath::test() {
        std::vector<ll> l {8, 123456789, 1288561398769758};
        std::vector<ll> r {10, 123456790, 1288561398769758};
        std::vector<std::string> directions {"DDDRRR", "DDRRDR", "RRRDDD"};
        std::vector<ll> expect {2, 1, 0};
        for (int i = 0; i < expect.size(); i++) {
            ll actual = countGoodIntegersOnPath(l[i], r[i], directions[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("100899", leetcode::CountGoodIntegersOnAGridPath);