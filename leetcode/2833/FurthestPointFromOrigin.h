//
// Created by Ruiguo Yang on 2026/4/24.
//

#ifndef ALGORITHM_FURTHESTPOINTFROMORIGIN_H
#define ALGORITHM_FURTHESTPOINTFROMORIGIN_H

#include <cstring>
#include "../Base.h"

namespace leetcode {
    class FurthestPointFromOrigin: public Base {
    public:
        int furthestDistanceFromOrigin(std::string& moves);
        void test() override;
    };
}


#endif //ALGORITHM_FURTHESTPOINTFROMORIGIN_H