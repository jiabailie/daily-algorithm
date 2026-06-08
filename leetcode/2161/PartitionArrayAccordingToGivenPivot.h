//
// Created by Ruiguo Yang on 2026/6/8.
//

#ifndef ALGORITHM_PARTITIONARRAYACCORDINGTOGIVENPIVOT_H
#define ALGORITHM_PARTITIONARRAYACCORDINGTOGIVENPIVOT_H

#include "../Base.h"

namespace leetcode {
    class PartitionArrayAccordingToGivenPivot: public Base {
    public:
        std::vector<int> pivotArray(std::vector<int>& nums, int pivot);
        void test() override;
    };
}

#endif //ALGORITHM_PARTITIONARRAYACCORDINGTOGIVENPIVOT_H