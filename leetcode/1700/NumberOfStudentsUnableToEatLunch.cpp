//
// Created by Ruiguo Yang on 2026/6/9.
//

#include "NumberOfStudentsUnableToEatLunch.h"

#include <deque>
#include <iostream>
#include <ostream>
#include <queue>

namespace leetcode {
    int NumberOfStudentsUnableToEatLunch::countStudents(std::vector<int> &students, std::vector<int> &sandwiches) {
        std::vector<int> cnt(2, 0);
        for (int x: students) {
            cnt[x]++;
        }

        std::queue<int> ique(std::deque<int>(students.begin(), students.end()));
        for (int s: sandwiches) {
            if (cnt[s] == 0) {
                return ique.size();
            }

            while (ique.front() != s) {
                int front = ique.front();
                ique.pop();
                ique.push(front);
            }
            ique.pop();
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
