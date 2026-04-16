//
// Created by Ruiguo Yang on 2026/4/16.
//

#ifndef ALGORITHM_CLOSETEQUALELEMENTQUERIES_H
#define ALGORITHM_CLOSETEQUALELEMENTQUERIES_H

#include <vector>
#include "../Base.h"

namespace leetcode {
    class ClosetEqualElementQueries: public Base {
    public:
        std::vector<int> solveQueries(std::vector<int>& nums, std::vector<int>& queries);
        void test() override;
    };
};


#endif //ALGORITHM_CLOSETEQUALELEMENTQUERIES_H