//
// Created by Ruiguo Yang on 2026/4/27.
//

#ifndef ALGORITHM_CHECKIFTHEREISAVALIDPATHINAGRID_H
#define ALGORITHM_CHECKIFTHEREISAVALIDPATHINAGRID_H


#include "../Base.h"

namespace leetcode {
    class CheckIfThereIsAValidPathInAGrid: public Base {
    public:
        bool hasValidPath(std::vector<std::vector<int>>& grid);
        void test() override;
    };
}


#endif //ALGORITHM_CHECKIFTHEREISAVALIDPATHINAGRID_H