//
// Created by ruiguo on 2026/7/15.
//

#ifndef ALGORITHM_SUPERUGLYNUMBER_H
#define ALGORITHM_SUPERUGLYNUMBER_H

#include "../Base.h"

namespace leetcode {
    class SuperUglyNumber: public Base {
    public:
        int nthSuperUglyNumber(int n, std::vector<int>& primes);
        void test() override;
    };
}

#endif //ALGORITHM_SUPERUGLYNUMBER_H
