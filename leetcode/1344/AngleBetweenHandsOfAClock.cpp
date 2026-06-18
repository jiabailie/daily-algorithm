//
// Created by ruiguo on 2026/6/18.
//

#include "AngleBetweenHandsOfAClock.h"

#include <iostream>

namespace leetcode {
    double AngleBetweenHandsOfAClock::angleClock(int hour, int minutes) {
        int d = std::abs(hour * 60 - minutes * 11);
        return std::min(d, 720 - d) * 0.5;
    }

    void AngleBetweenHandsOfAClock::test() {
        std::vector<int> hour {12,3,3};
        std::vector<int> minutes {30,30,15};
        std::vector<double> expect {165,75,7.5};
        double delta = 10e-5;
        for (int i = 0; i < expect.size(); i++) {
            double actual = angleClock(hour[i], minutes[i]);
            std::cout << (abs(actual - expect[i]) <= delta ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1344", leetcode::AngleBetweenHandsOfAClock);