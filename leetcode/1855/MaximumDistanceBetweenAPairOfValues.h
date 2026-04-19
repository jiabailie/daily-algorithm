//
// Created by Ruiguo Yang on 2026/4/19.
//

#ifndef ALGORITHM_MAXIMUMDISTANCEBETWEENAPAIROFVALUES_H
#define ALGORITHM_MAXIMUMDISTANCEBETWEENAPAIROFVALUES_H

#include <vector>
#include "../Base.h"

namespace  leetcode {
    class MaximumDistanceBetweenAPairOfValues: public Base {
    public:
        int maxDistance1(std::vector<int>& nums1, std::vector<int>& nums2);
        int maxDistance2(std::vector<int>& nums1, std::vector<int>& nums2);
        void test() override;
    };
}


#endif //ALGORITHM_MAXIMUMDISTANCEBETWEENAPAIROFVALUES_H