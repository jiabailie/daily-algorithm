//
// Created by Ruiguo Yang on 2026/4/18.
//

#include "AnglesOfaTriangle.h"

#include <iostream>
#include <ostream>
#include <vector>

namespace leetcode {
    std::vector<double> AnglesOfaTriangle::internalAngles(std::vector<int> &sides) {
        double a = static_cast<double>(sides[0]);
        double b = static_cast<double>(sides[1]);
        double c = static_cast<double>(sides[2]);

        if (a + b <= c || a + c <= b || b + c <= a) {
            return {};
        }

        double PI = 180.0 / std::acos(-1);

        double angleA = std::acos((b * b + c * c - a * a) / (2 * b * c)) * PI;
        double angleB = std::acos((a * a + c * c - b * b) / (2 * a * c)) * PI;
        double angleC = std::acos((a * a + b * b - c * c) / (2 * a * b)) * PI;

        std::vector<double> angles = {
            angleA, angleB, angleC
        };
        std::sort(angles.begin(), angles.end());
        return angles;
    }

    void AnglesOfaTriangle::test() {
        std::vector<std::vector<int>> sides {
            {3,4,5},
            {2,4,2}
        };
        std::vector<std::vector<double>> angles {
            {36.86990,53.13010,90.00000},
            {}
        };
        int t = sides.size();
        double delta = 1e-5;

        for (int i = 0; i < t; ++i) {
            std::vector<double> actual = internalAngles(sides[i]);
            std::vector<double> expect = angles[i];

            bool flag = actual.size() == expect.size();
            for (int j = 0; flag && j < expect.size(); ++j) {
                double d = abs(actual[j] - expect[j]);
                if (d > delta) {
                    flag = false;
                }
            }
            std::cout << (flag ? "PASS" : "FAIL") << std::endl;
        }

    }
}

REGISTER_LEETCODE_SOLUTION("3899", leetcode::AnglesOfaTriangle);