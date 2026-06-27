//
// Created by Ruiguo Yang on 2026/6/27.
//

#include "FindTheMaximumNumberOfElementsInSubset.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int FindTheMaximumNumberOfElementsInSubset::maximumLength(std::vector<int> &nums) {
        std::map<int, int> cnt;
        for (int x: nums) {
            cnt[x]++;
        }

        int ans = 1;
        if (cnt.find(1) != cnt.end()) {
            ans = cnt[1] % 2 == 1 ? cnt[1] : cnt[1] - 1;
        }
        for (auto [k, v]: cnt) {
            if (k == 1 || v == 1) {
                continue;
            }

            int curr = 2;
            long long d = k;
            while (true) {
                long long next = 1LL * d * d;
                if (cnt.find(next) == cnt.end()) {
                    curr--;
                    break;
                }
                if (cnt[next] == 1) {
                    curr++;
                    break;
                }
                if (next >= INT_MAX) {
                    curr++;
                    break;
                }

                curr += 2;
                d = next;
            }
            ans = std::max(ans, curr);
        }
        return ans;
    }

    void FindTheMaximumNumberOfElementsInSubset::test() {
        std::vector<std::vector<int>> nums {
            {5,4,1,2,2},
            {1,3,2,4}
        };
        std::vector<int> expect {3,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maximumLength(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3020", leetcode::FindTheMaximumNumberOfElementsInSubset);