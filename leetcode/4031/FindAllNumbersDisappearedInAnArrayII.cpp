//
// Created by Ruiguo on 24/8/2026.
//

#include "FindAllNumbersDisappearedInAnArrayII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<std::vector<int>> FindAllNumbersDisappearedInAnArrayII::findDisappearedNumbers(std::vector<int>& nums, int lower, int upper) {
        std::vector<bool> f(upper + 2, false);
        for (int x: nums) {
            if (x > upper + 1) {
                continue;
            }
            f[x] = true;
        }
        f[upper + 1] = true;

        std::vector<std::vector<int>> ans;
        int s = -1;
        for (int i = lower; i <= upper + 1; ++i) {
            if (!f[i]) {
                if (s == -1) {
                    s = i;
                }
                continue;
            }

            if (i - 1 >= lower && !f[i - 1]) {
                if (s != -1) {
                    std::vector<int> section(2, 0);
                    section[0] = s;
                    section[1] = i - 1;
                    ans.push_back(section);
                    s = -1;
                }
            }
        }
        return ans;
    }

    void FindAllNumbersDisappearedInAnArrayII::test() {
        std::vector<std::vector<int>> nums {
            {3,9,7},{1,1},{2,3,5}
        };
        std::vector<int> lower {1,5,2};
        std::vector<int> upper {12,7,3};
        std::vector<std::vector<std::vector<int>>> expect {
            {{1,2},{4,6},{8,8},{10,12}},
            {{5,7}},
            {}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<std::vector<int>> actual = findDisappearedNumbers(nums[i], lower[i], upper[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("4031", leetcode::FindAllNumbersDisappearedInAnArrayII);