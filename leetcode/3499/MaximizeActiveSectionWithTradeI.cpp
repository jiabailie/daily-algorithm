//
// Created by ruiguo on 2026/7/21.
//

#include "MaximizeActiveSectionWithTradeI.h"

#include <climits>
#include <iostream>
#include <ostream>

namespace leetcode {
    int MaximizeActiveSectionWithTradeI::maxActiveSectionsAfterTrade(std::string s) {
        int total = 0;
        int mx = 0;
        int pre = INT_MIN;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt++;
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                if (s[i] == '1') {
                    total += cnt;
                } else {
                    mx = std::max(mx, pre + cnt);
                    pre = cnt;
                }
                cnt = 0;
            }
        }
        return total + mx;
    }

    void MaximizeActiveSectionWithTradeI::test() {
        std::vector<std::string> s {"01","0100","1000100","01010"};
        std::vector<int> expect {1,4,7,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = maxActiveSectionsAfterTrade(s[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3499", leetcode::MaximizeActiveSectionWithTradeI);
