//
// Created by Ruiguo on 12/7/2026.
//

#ifndef ALGORITHM_MAXIMUMCONSISTENTCOLUMNSINAGRID_H
#define ALGORITHM_MAXIMUMCONSISTENTCOLUMNSINAGRID_H

#include "../Base.h"

namespace leetcode {
    class MaximumConsistentColumnsInAGrid: public Base {
    public:
        int maxConsistentColumns(std::vector<std::vector<int>>& grid, int limit);
        void test() override;
    };
}



#endif //ALGORITHM_MAXIMUMCONSISTENTCOLUMNSINAGRID_H
