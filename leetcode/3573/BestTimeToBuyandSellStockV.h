//
// Created by Ruiguo Yang on 2025/12/17.
//

#ifndef ALGORITHM_BESTTIMETOBUYANDSELLSTOCKV_H
#define ALGORITHM_BESTTIMETOBUYANDSELLSTOCKV_H

#include <vector>
#include "../Base.h"

namespace leetcode {
    class BestTimeToBuyandSellStockV: public Base {
    public:
        long long maximumProfit(std::vector<int>& prices, int k);
        void test() override;
    };
} // leetcode

#endif //ALGORITHM_BESTTIMETOBUYANDSELLSTOCKV_H
