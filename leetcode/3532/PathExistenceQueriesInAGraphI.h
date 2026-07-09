//
// Created by ruiguo on 2026/7/9.
//

#ifndef ALGORITHM_PATHEXISTENCEQUERIESINAGRAPHI_H
#define ALGORITHM_PATHEXISTENCEQUERIESINAGRAPHI_H

#include "../Base.h"

namespace leetcode {
    class PathExistenceQueriesInAGraphI: public Base {
    public:
        std::vector<bool> pathExistenceQueries(int n, std::vector<int>& nums, int maxDiff, std::vector<std::vector<int>>& queries);
        void test() override;
    };
}

#endif //ALGORITHM_PATHEXISTENCEQUERIESINAGRAPHI_H
