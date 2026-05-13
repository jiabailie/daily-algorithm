//
// Created by Ruiguo Yang on 2026/5/13.
//

#ifndef ALGORITHM_MINIMUMMOVESTOMAKEARRAYCOMPLEMENTARY_H
#define ALGORITHM_MINIMUMMOVESTOMAKEARRAYCOMPLEMENTARY_H

#include "../Base.h"

namespace leetcode {
    class MinimumMovesToMakeArrayComplementary: public Base {
    public:
        int minMoves(std::vector<int>& nums, int limit);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMUMMOVESTOMAKEARRAYCOMPLEMENTARY_H