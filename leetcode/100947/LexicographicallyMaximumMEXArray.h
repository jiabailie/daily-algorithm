//
// Created by Ruiguo Yang on 2026/5/31.
//

#ifndef ALGORITHM_LEXICOGRAPHICALLYMAXIMUMMEXARRAY_H
#define ALGORITHM_LEXICOGRAPHICALLYMAXIMUMMEXARRAY_H

#include "../Base.h"

namespace leetcode {
    class LexicographicallyMaximumMEXArray: public Base {
    public:
        std::vector<int> maximumMEX(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_LEXICOGRAPHICALLYMAXIMUMMEXARRAY_H