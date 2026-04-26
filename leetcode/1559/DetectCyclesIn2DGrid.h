//
// Created by Ruiguo Yang on 2026/4/26.
//

#ifndef ALGORITHM_DETECTCYCLESIN2DGRID_H
#define ALGORITHM_DETECTCYCLESIN2DGRID_H

#include "../Base.h"

namespace leetcode {
    class DetectCyclesIn2DGrid: public Base {
    private:
        static constexpr int DIRS[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    public:
        bool containsCycle(std::vector<std::vector<char>>& grid);
        void test() override;
    };
}


#endif //ALGORITHM_DETECTCYCLESIN2DGRID_H