//
// Created by ruiguo on 2026/7/2.
//

#ifndef ALGORITHM_FINDASAFEWALKTHROUGHAGRID_H
#define ALGORITHM_FINDASAFEWALKTHROUGHAGRID_H

#include "../Base.h"

namespace leetcode {
    class FindASafeWalkThroughAGrid: public Base {
    private:
        static constexpr int DIRS[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    public:
        bool findSafeWalk(std::vector<std::vector<int>>& grid, int health);
        void test() override;
    };
}


#endif //ALGORITHM_FINDASAFEWALKTHROUGHAGRID_H
