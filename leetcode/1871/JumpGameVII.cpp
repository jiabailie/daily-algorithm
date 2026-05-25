//
// Created by Ruiguo Yang on 2026/5/25.
//

#include "JumpGameVII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    bool JumpGameVII::canReach(std::string s, int minJump, int maxJump) {
        int n = s.size();
        std::vector<int8_t> f(n);
        std::vector<int> sum(n + 1);

        f[0] = true;
        sum[1] = 1;

        for (int i = 1; i < n; ++i) {
            f[i] = i >= minJump && s[i] == '0' && sum[i - minJump + 1] > sum[std::max(i - maxJump, 0)];
            sum[i + 1] = sum[i] + f[i];
        }
        return f[n - 1];
    }

    void JumpGameVII::test() {
        std::vector<std::string> s {
            "011010",
            "01101110"
        };
        std::vector<int> minJump {2,3};
        std::vector<int> maxJump {3,3};
        std::vector<bool> expect {true,false};
        for (int i = 0; i < expect.size(); i++) {
            bool actual = canReach(s[i], minJump[i], maxJump[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1871", leetcode::JumpGameVII);
