//
// Created by Ruiguo Yang on 2026/6/13.
//

#ifndef ALGORITHM_WEIGHTEDWORDMAPPING_H
#define ALGORITHM_WEIGHTEDWORDMAPPING_H

#include "../Base.h"

namespace leetcode {
    class WeightedWordMapping: public Base {
    public:
        std::string mapWordWeights(std::vector<std::string>& words, std::vector<int>& weights);
        void test() override;
    };
}

#endif //ALGORITHM_WEIGHTEDWORDMAPPING_H