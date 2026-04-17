//
// Created by Ruiguo Yang on 2026/4/17.
//

#ifndef ALGORITHM_MINIMUMABSOLUTEDISTANCEBETWEENMIRRORPAIRS_H
#define ALGORITHM_MINIMUMABSOLUTEDISTANCEBETWEENMIRRORPAIRS_H

#include <vector>

#include "../Base.h"

namespace leetcode {
    class MinimumAbsoluteDistanceBetweenMirrorPairs: public Base {
    public:
        int reverse(int x);
        int minMirrorPairDistance0(std::vector<int>& nums);
        int minMirrorPairDistance1(std::vector<int>& nums);
        void test() override;
    };
}


#endif //ALGORITHM_MINIMUMABSOLUTEDISTANCEBETWEENMIRRORPAIRS_H