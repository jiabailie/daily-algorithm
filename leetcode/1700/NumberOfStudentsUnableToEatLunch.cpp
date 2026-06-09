//
// Created by Ruiguo Yang on 2026/6/9.
//

#include "NumberOfStudentsUnableToEatLunch.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int NumberOfStudentsUnableToEatLunch::countStudents(std::vector<int> &students, std::vector<int> &sandwiches) {
        std::vector<int> cnt(2, 0);
        for (int x: students) {
            cnt[x]++;
        }

        for (int s: sandwiches) {
            if (cnt[s] == 0) {
                return cnt[1 - s];
            }
            cnt[s]--;
        }
        return 0;
    }

    void NumberOfStudentsUnableToEatLunch::test() {
        std::vector<std::vector<int>> students{
            {1,1,0,0},
            {1,1,1,0,0,1}
        };
        std::vector<std::vector<int>> sandwiches{
            {0,1,0,1},
            {1,0,0,0,1,1}
        };
        std::vector<int> expect {0,3};
        for (int i = 0; i < expect.size(); i++) {
            int actual = countStudents(students[i], sandwiches[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1700", leetcode::NumberOfStudentsUnableToEatLunch);
