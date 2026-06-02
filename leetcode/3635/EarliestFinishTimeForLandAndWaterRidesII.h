//
// Created by Ruiguo Yang on 2026/6/2.
//

#ifndef ALGORITHM_EARLIESTFINISHTIMEFORLANDANDWATERRIDESII_H
#define ALGORITHM_EARLIESTFINISHTIMEFORLANDANDWATERRIDESII_H

#include "../Base.h"

namespace leetcode {
    class EarliestFinishTimeForLandAndWaterRidesII: public Base {
    public:
        int solve(std::vector<int>& startA, std::vector<int>& durationA, std::vector<int>& startB, std::vector<int>& durationB);
        int earliestFinishTime(std::vector<int>& landStartTime, std::vector<int>& landDuration, std::vector<int>& waterStartTime, std::vector<int>& waterDuration);
        void test() override;
    };
}

#endif //ALGORITHM_EARLIESTFINISHTIMEFORLANDANDWATERRIDESII_H