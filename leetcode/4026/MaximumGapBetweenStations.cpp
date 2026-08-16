//
// Created by Ruiguo on 16/8/2026.
//

#include "MaximumGapBetweenStations.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximumGapBetweenStations::maximumGap(std::string skill, std::string station) {
        int n = skill.size();
        int m = station.size();

        std::vector<int> left(n);
        for (int i = 0, j = 0; i < n; ++i, ++j) {
            while (skill[i] != station[j]) {
                j++;
            }
            left[i] = j;
        }

        std::vector<int> right(n);
        for (int i = n - 1, j = m - 1; i >= 0; --i, --j) {
            while (skill[i] != station[j]) {
                j--;
            }
            right[i] = j;
        }

        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = std::max(ans, right[i + 1] - left[i]);
        }
        return ans;
    }

    void MaximumGapBetweenStations::test() {
        std::vector<std::string> skill {"aa","xyz","cbc"};
        std::vector<std::string> station {"aaaa","xyzz","cbcdbc"};
        std::vector<int> expect {3,2,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maximumGap(skill[i], station[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("4026", leetcode::MaximumGapBetweenStations);