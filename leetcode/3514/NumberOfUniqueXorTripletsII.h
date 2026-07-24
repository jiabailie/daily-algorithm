//
// Created by Ruiguo on 24/7/2026.
//

#ifndef ALGORITHM_NUMBEROFUNIQUEXORTRIPLETSII_H
#define ALGORITHM_NUMBEROFUNIQUEXORTRIPLETSII_H

#include "../Base.h"

namespace leetcode {
    class NumberOfUniqueXorTripletsII: public Base {
    public:
        int uniqueXorTriplets(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_NUMBEROFUNIQUEXORTRIPLETSII_H
