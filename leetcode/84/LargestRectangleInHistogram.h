//
// Created by Ruiguo Yang on 2026/6/5.
//

#ifndef ALGORITHM_LARGESTRECTANGLEINHISTOGRAM_H
#define ALGORITHM_LARGESTRECTANGLEINHISTOGRAM_H

#include "../Base.h"

namespace leetcode {
    class LargestRectangleInHistogram: public Base {
    public:
        int largestRectangleArea(std::vector<int>& heights);
        void test() override;
    };
}

#endif //ALGORITHM_LARGESTRECTANGLEINHISTOGRAM_H