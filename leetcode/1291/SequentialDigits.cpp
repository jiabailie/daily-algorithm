//
// Created by ruiguo on 2026/7/13.
//

#include "SequentialDigits.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<int> SequentialDigits::sequentialDigits(int low, int high) {
        std::string s("123456789");
        std::vector<int> ans;
        for (int i = 2; i <= 9; ++i) {
            for (int j = 0; j + i <= 9; ++j) {
                int x = 0;
                for (int k = 0; k < i; ++k) {
                    x = x * 10 + (s[j + k] - '0');
                }
                if (low <= x && x <= high) {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }

    void SequentialDigits::test() {
        std::vector<int> low {100,1000,100};
        std::vector<int> high {300,13000,1000000000};
        std::vector<std::vector<int>> expect {
            {123,234},
            {1234,2345,3456,4567,5678,6789,12345},
            {123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,
                34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,
                12345678,23456789,123456789}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = sequentialDigits(low[i], high[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1291", leetcode::SequentialDigits);