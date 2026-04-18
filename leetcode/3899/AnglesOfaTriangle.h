//
// Created by Ruiguo Yang on 2026/4/18.
//

#ifndef ALGORITHM_ANGLESOFATRIANGLE_H
#define ALGORITHM_ANGLESOFATRIANGLE_H

#include <vector>

#include "../Base.h"

namespace leetcode {
    class AnglesOfaTriangle: public Base {
    public:
        std::vector<double> internalAngles(std::vector<int>& sides);
        void test() override;
    };
}

#endif //ALGORITHM_ANGLESOFATRIANGLE_H