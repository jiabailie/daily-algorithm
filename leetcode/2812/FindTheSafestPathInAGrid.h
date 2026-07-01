//
// Created by Ruiguo Yang on 2026/7/1.
//

#ifndef ALGORITHM_FINDTHESAFESTPATHINAGRID_H
#define ALGORITHM_FINDTHESAFESTPATHINAGRID_H

#include "../Base.h"

namespace leetcode {
    class FindTheSafestPathInAGrid: public Base {
    private:
        static constexpr int dirs[4][2] = {{-1,0},{1,0},{0,-1}, {0,1}};
    public:
        int maximumSafenessFactor(std::vector<std::vector<int>>& grid);
        void test() override;
    };
}

#endif //ALGORITHM_FINDTHESAFESTPATHINAGRID_H