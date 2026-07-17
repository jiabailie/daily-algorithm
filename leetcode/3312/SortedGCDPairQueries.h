//
// Created by ruiguo on 2026/7/17.
//

#ifndef ALGORITHM_SORTEDGCDPAIRQUERIES_H
#define ALGORITHM_SORTEDGCDPAIRQUERIES_H

#include "../Base.h"

namespace leetcode {
    class SortedGCDPairQueries: public Base {
    public:
        std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries);
        void test() override;
    };
}

#endif //ALGORITHM_SORTEDGCDPAIRQUERIES_H
