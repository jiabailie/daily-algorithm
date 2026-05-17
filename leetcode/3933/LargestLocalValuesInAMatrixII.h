//
// Created by Ruiguo Yang on 2026/5/17.
//

#ifndef ALGORITHM_LARGESTLOCALVALUESINAMATRIXII_H
#define ALGORITHM_LARGESTLOCALVALUESINAMATRIXII_H

#include "../Base.h"

namespace leetcode {
    class LargestLocalValuesInAMatrixII: public Base {
    public:
        int countLocalMaximums(std::vector<std::vector<int>>& matrix);
        void test() override;
    };
}

#endif //ALGORITHM_LARGESTLOCALVALUESINAMATRIXII_H