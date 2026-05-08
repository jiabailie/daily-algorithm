//
// Created by Ruiguo Yang on 2026/5/8.
//

#ifndef ALGORITHM_MINIMUMJUMPSTOREACHEND_H
#define ALGORITHM_MINIMUMJUMPSTOREACHEND_H

#include "../Base.h"

namespace leetcode {
    class MinimumJumpsToReachEnd: public Base {
    private:
        std::vector<std::vector<int>> getPrimeFactors();
    public:
        int minJumps(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMJUMPSTOREACHEND_H