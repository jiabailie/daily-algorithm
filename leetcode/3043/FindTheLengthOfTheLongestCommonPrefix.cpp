//
// Created by Ruiguo Yang on 2026/5/21.
//

#include "FindTheLengthOfTheLongestCommonPrefix.h"

#include <iostream>
#include <ostream>
#include <unordered_set>

namespace leetcode {
    int FindTheLengthOfTheLongestCommonPrefix::longestCommonPrefix1(std::vector<int> &arr1, std::vector<int> &arr2) {
        std::unordered_set<std::string> s;
        for (int x: arr1) {
            std::string sx = std::to_string(x);
            for (int i = 1; i <= sx.length(); i++) {
                s.insert(sx.substr(0, i));
            }
        }

        int ans = 0;
        for (int x: arr2) {
            std::string sx = std::to_string(x);
            for (int i = 1; i <= sx.length(); i++) {
                if (s.count(sx.substr(0, i)) > 0) {
                    ans = std::max(ans, i);
                }
            }
        }
        return ans;
    }

    int FindTheLengthOfTheLongestCommonPrefix::longestCommonPrefix2(std::vector<int> &arr1, std::vector<int> &arr2) {
        std::unordered_set<int> s;
        for (int x: arr1) {
            while (x) {
                s.insert(x);
                x /= 10;
            }
        }

        int mx = 0;
        for (int x: arr2) {
            while (x && s.count(x) == 0) {
                x /= 10;
            }
            mx = std::max(mx, x);
        }
        return (mx == 0 ? 0 : std::to_string(mx).length());
    }

    void FindTheLengthOfTheLongestCommonPrefix::test() {
        std::vector<std::vector<int>> arr1 {
            {1,10,100},
            {1,2,3}
        };
        std::vector<std::vector<int>> arr2 {
            {1000},
            {4,4}
        };
        std::vector<int> expect {3,0};

        for (int i = 0; i < expect.size(); i++) {
            int actual = longestCommonPrefix1(arr1[i], arr2[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }

        for (int i = 0; i < expect.size(); i++) {
            int actual = longestCommonPrefix2(arr1[i], arr2[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3043", leetcode::FindTheLengthOfTheLongestCommonPrefix);