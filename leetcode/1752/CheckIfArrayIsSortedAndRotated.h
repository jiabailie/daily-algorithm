//
// Created by Ruiguo Yang on 2026/5/23.
//

#ifndef ALGORITHM_CHECKIFARRAYISSORTEDANDROTATED_H
#define ALGORITHM_CHECKIFARRAYISSORTEDANDROTATED_H

#include "../Base.h"

namespace leetcode {
    class CheckIfArrayIsSortedAndRotated: public Base {
    public:
        bool check(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_CHECKIFARRAYISSORTEDANDROTATED_H