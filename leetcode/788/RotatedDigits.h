//
// Created by Ruiguo Yang on 2026/5/2.
//

#ifndef ALGORITHM_ROTATEDDIGITS_H
#define ALGORITHM_ROTATEDDIGITS_H

#include "../Base.h"

namespace leetcode {
    class RotatedDigits: public Base {
    private:
        bool isValid(int x);
    public:
        int rotatedDigits(int n);
        void test() override;
    };
}

#endif //ALGORITHM_ROTATEDDIGITS_H