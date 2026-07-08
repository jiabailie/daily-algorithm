//
// Created by ruiguo on 2026/7/8.
//

#include "ConcatenateNonZeroDigitsAndMultipleBySumII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> ConcatenateNonZeroDigitsAndMultipleBySumII::sumAndMultiply(std::string s, std::vector<std::vector<int> > &queries) {
        int n = s.size();
        std::vector<int> sum(n + 1, 0);
        std::vector<int> sumNonZero(n + 1, 0);
        std::vector<long long> num(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int t = s[i] - '0';
            sum[i + 1] = sum[i] + t;
            sumNonZero[i + 1] = sumNonZero[i] + (t > 0);
            num[i + 1] = t == 0 ? num[i] : (num[i] * 10LL + t) % MOD;
        }

        int m = queries.size();
        std::vector<int> ans(m, 0);
        for (int i = 0; i < m; ++i) {
            int s = queries[i][0];
            int e = queries[i][1] + 1;
            int length = sumNonZero[e] - sumNonZero[s];
            long long deltaNum = num[e] - 1LL * num[s] * pow10[length] % MOD + MOD;
            ans[i] = (deltaNum * (sum[e] - sum[s])) % MOD;
        }
        return ans;
    }

    void ConcatenateNonZeroDigitsAndMultipleBySumII::test() {
        std::vector<std::string> ss {
            "10203004",
            "1000",
            "9876543210"
        };
        std::vector<std::vector<std::vector<int>>> queries {
            {{0,7},{1,3},{4,6}},
            {{0,3},{1,1}},
            {{0,9}}
        };
        std::vector<std::vector<int>> expect {
            {12340, 4, 9},
            {1,0},
            {444444137}
        };
        for (int i = 0; i < expect.size(); ++i) {
            std::vector<int> actual = sumAndMultiply(ss[i], queries[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3756", leetcode::ConcatenateNonZeroDigitsAndMultipleBySumII);