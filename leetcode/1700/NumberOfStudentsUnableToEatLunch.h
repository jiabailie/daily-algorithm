//
// Created by Ruiguo Yang on 2026/6/9.
//

#ifndef ALGORITHM_NUMBEROFSTUDENTSUNABLETOEATLUNCH_H
#define ALGORITHM_NUMBEROFSTUDENTSUNABLETOEATLUNCH_H

#include "../Base.h"

namespace leetcode {
    class NumberOfStudentsUnableToEatLunch: public Base {
    public:
        int countStudents(std::vector<int>& students, std::vector<int>& sandwiches);
        void test() override;
    };
}

#endif //ALGORITHM_NUMBEROFSTUDENTSUNABLETOEATLUNCH_H