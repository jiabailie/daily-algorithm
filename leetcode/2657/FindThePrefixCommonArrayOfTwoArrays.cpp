//
// Created by Ruiguo Yang on 2026/5/20.
//

#include "FindThePrefixCommonArrayOfTwoArrays.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int FindThePrefixCommonArrayOfTwoArrays::countOne(uint64_t x) {
        int ans = 0;
        while (x) {
            ans++;
            x &= (x - 1ULL);
        }
        return ans;
    }

    std::vector<int> FindThePrefixCommonArrayOfTwoArrays::findThePrefixCommonArray(std::vector<int> &A, std::vector<int> &B) {
        int n = A.size();
        std::vector<int> ans(n);
        uint64_t a = 0;
        uint64_t b = 0;
        for (int i = 0; i < n; i++) {
            a |= (1ULL << A[i]);
            b |= (1ULL << B[i]);
            ans[i] = countOne(a & b);
        }
        return ans;
    }

    void FindThePrefixCommonArrayOfTwoArrays::test() {
        std::vector<std::vector<int>> a {
            {1,3,2,4},
            {2,3,1}
        };
        std::vector<std::vector<int>> b {
            {3,1,2,4},
            {3,1,2}
        };
        std::vector<std::vector<int>> expect {
            {0,2,3,4},
            {0,1,3}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = findThePrefixCommonArray(a[i], b[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2657", leetcode::FindThePrefixCommonArrayOfTwoArrays);
