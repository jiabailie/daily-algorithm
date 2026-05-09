//
// Created by Ruiguo Yang on 2026/5/9.
//

#ifndef ALGORITHM_CYCLICALLYROTATINGAGRID_H
#define ALGORITHM_CYCLICALLYROTATINGAGRID_H

#include "../Base.h"

namespace leetcode {
    class CyclicallyRotatingAGrid: public Base {
    public:
        std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>>& grid, int k);
        void test() override;
    };
}

#endif //ALGORITHM_CYCLICALLYROTATINGAGRID_H