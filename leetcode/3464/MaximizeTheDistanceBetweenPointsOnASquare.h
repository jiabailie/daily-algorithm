//
// Created by Ruiguo Yang on 2026/4/25.
//

#ifndef ALGORITHM_MAXIMIZETHEDISTANCEBETWEENPOINTSONASQUARE_H
#define ALGORITHM_MAXIMIZETHEDISTANCEBETWEENPOINTSONASQUARE_H


#include <vector>
#include "../Base.h"

namespace leetcode {
    class MaximizeTheDistanceBetweenPointsOnASquare: public Base {
    public:
        int maxDistance(int side, std::vector<std::vector<int>>& points, int k);
        void test() override;
    };
}


#endif //ALGORITHM_MAXIMIZETHEDISTANCEBETWEENPOINTSONASQUARE_H