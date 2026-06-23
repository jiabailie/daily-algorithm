//
// Created by ruiguo on 2026/6/23.
//

#ifndef ALGORITHM_MINIMUMLIGHTSTOILLUMINATEAROAD_H
#define ALGORITHM_MINIMUMLIGHTSTOILLUMINATEAROAD_H

#include "../Base.h"

namespace leetcode {
    class MinimumLightsToIlluminateARoad: public Base {
    public:
        int minLights(std::vector<int>& lights);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMLIGHTSTOILLUMINATEAROAD_H
