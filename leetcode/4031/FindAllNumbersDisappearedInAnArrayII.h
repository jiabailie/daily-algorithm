//
// Created by Ruiguo on 24/8/2026.
//

#ifndef ALGORITHM_FINDALLNUMBERSDISAPPEAREDINANARRAYII_H
#define ALGORITHM_FINDALLNUMBERSDISAPPEAREDINANARRAYII_H

#include "../Base.h"

namespace leetcode {
    class FindAllNumbersDisappearedInAnArrayII: public Base {
    public:
        std::vector<std::vector<int>> findDisappearedNumbers(std::vector<int>& nums, int lower, int upper);
        void test() override;
    };
}

#endif //ALGORITHM_FINDALLNUMBERSDISAPPEAREDINANARRAYII_H
