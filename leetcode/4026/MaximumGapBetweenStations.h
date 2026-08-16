//
// Created by Ruiguo on 16/8/2026.
//

#ifndef ALGORITHM_MAXIMUMGAPBETWEENSTATIONS_H
#define ALGORITHM_MAXIMUMGAPBETWEENSTATIONS_H

#include "../Base.h"

namespace leetcode {
    class MaximumGapBetweenStations: public Base {
    public:
        int maximumGap(std::string skill, std::string station);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMGAPBETWEENSTATIONS_H
