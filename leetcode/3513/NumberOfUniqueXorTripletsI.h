//
// Created by ruiguo on 2026/7/23.
//

#ifndef ALGORITHM_NUMBEROFUNIQUEXORTRIPLETSI_H
#define ALGORITHM_NUMBEROFUNIQUEXORTRIPLETSI_H

#include "../Base.h"

namespace leetcode {
    class NumberOfUniqueXorTripletsI: public Base {
    public:
        int uniqueXorTriplets(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_NUMBEROFUNIQUEXORTRIPLETSI_H
