//
// Created by Ruiguo Yang on 2026/7/4.
//

#ifndef ALGORITHM_MINIMUMSCOREOFAPATHBETWEENTWOCITIES_H
#define ALGORITHM_MINIMUMSCOREOFAPATHBETWEENTWOCITIES_H

#include "../Base.h"

namespace leetcode {
    class MinimumScoreOfAPathBetweenTwoCities: public Base {
    public:
        int minScore(int n, std::vector<std::vector<int>>& roads);
        void test() override;
    };
}



#endif //ALGORITHM_MINIMUMSCOREOFAPATHBETWEENTWOCITIES_H