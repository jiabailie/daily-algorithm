//
// Created by Ruiguo Yang on 2026/5/3.
//

#ifndef ALGORITHM_COMPARESUMSOFBITONICPARTS_H
#define ALGORITHM_COMPARESUMSOFBITONICPARTS_H

#include "../Base.h"

namespace leetcode {
    class CompareSumsOfBitonicParts: public Base {
    public:
        int compareBitonicSums(std::vector<int>& nums);
        void test() override;
    };
}


#endif //ALGORITHM_COMPARESUMSOFBITONICPARTS_H