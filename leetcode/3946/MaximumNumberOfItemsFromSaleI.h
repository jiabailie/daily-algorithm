//
// Created by Ruiguo Yang on 2026/6/1.
//

#ifndef ALGORITHM_MAXIMUMNUMBEROFITEMSFROMSALEI_H
#define ALGORITHM_MAXIMUMNUMBEROFITEMSFROMSALEI_H

#include "../Base.h"

namespace leetcode {
    class MaximumNumberOfItemsFromSaleI: public Base {
    public:
        int maximumSaleItems(std::vector<std::vector<int>>& items, int budget);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMNUMBEROFITEMSFROMSALEI_H