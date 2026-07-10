//
// Created by ruiguo on 2026/7/10.
//

#ifndef ALGORITHM_PATHEXISTENCEQUERIESINAGRAPHII_H
#define ALGORITHM_PATHEXISTENCEQUERIESINAGRAPHII_H

#include "../Base.h"

namespace leetcode {
    class PathExistenceQueriesInAGraphII: public Base {
    public:
        std::vector<int> pathExistenceQueries(int n, std::vector<int>& nums, int maxDiff, std::vector<std::vector<int>>& queries);
        void test() override;
    };
};

#endif //ALGORITHM_PATHEXISTENCEQUERIESINAGRAPHII_H
