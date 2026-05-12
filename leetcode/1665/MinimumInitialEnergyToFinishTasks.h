//
// Created by Ruiguo Yang on 2026/5/12.
//

#ifndef ALGORITHM_MINIMUMINITIALENERGYTOFINISHTASKS_H
#define ALGORITHM_MINIMUMINITIALENERGYTOFINISHTASKS_H

#include "../Base.h"

namespace leetcode {
    class MinimumInitialEnergyToFinishTasks: public Base {
    public:
        int minimumEffort(std::vector<std::vector<int>>& tasks);
        void test() override;
    };
}


#endif //ALGORITHM_MINIMUMINITIALENERGYTOFINISHTASKS_H