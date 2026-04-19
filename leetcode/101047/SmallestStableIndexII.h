//
// Created by Ruiguo Yang on 2026/4/19.
//

#ifndef ALGORITHM_SMALLESTSTABLEINDEXII_H
#define ALGORITHM_SMALLESTSTABLEINDEXII_H

#include <vector>
#include "../Base.h"

namespace  leetcode {
    class SmallestStableIndexII: public Base {
    public:
        int firstStableIndex(std::vector<int>& nums, int k);
        void test() override;
    };
}


#endif //ALGORITHM_SMALLESTSTABLEINDEXII_H