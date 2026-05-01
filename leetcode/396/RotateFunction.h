//
// Created by Ruiguo Yang on 2026/5/1.
//

#ifndef ALGORITHM_ROTATEFUNCTION_H
#define ALGORITHM_ROTATEFUNCTION_H


#include "../Base.h"

namespace leetcode {
    class RotateFunction: public Base {
    public:
        int maxRotateFunction(std::vector<int>& nums);
        void test() override;
    };
}


#endif //ALGORITHM_ROTATEFUNCTION_H