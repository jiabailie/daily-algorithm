//
// Created by Ruiguo Yang on 2026/6/15.
//

#ifndef ALGORITHM_FINDKPAIRSWITHSMALLESTSUMS_H
#define ALGORITHM_FINDKPAIRSWITHSMALLESTSUMS_H

#include "../Base.h"

namespace leetcode {
    class FindKPairsWithSmallestSums: public Base {
    public:
        std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k);
        void test() override;
    };
}


#endif //ALGORITHM_FINDKPAIRSWITHSMALLESTSUMS_H