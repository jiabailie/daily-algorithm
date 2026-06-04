//
// Created by Ruiguo Yang on 2026/6/4.
//

#ifndef ALGORITHM_DAILYTEMPERATURES_H
#define ALGORITHM_DAILYTEMPERATURES_H

#include "../Base.h"

namespace leetcode {
    class DailyTemperatures: public Base {
    public:
        std::vector<int> dailyTemperatures(std::vector<int>& temperatures);
        void test() override;;
    };
}

#endif //ALGORITHM_DAILYTEMPERATURES_H