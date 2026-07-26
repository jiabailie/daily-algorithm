//
// Created by Ruiguo on 26/7/2026.
//

#ifndef ALGORITHM_AGGREGATETWOTIMESERIES_H
#define ALGORITHM_AGGREGATETWOTIMESERIES_H

#include "../Base.h"

namespace leetcode {
    class AggregateTwoTimeSeries: public Base {
    public:
        std::vector<std::vector<int>> aggregateTimeSeries(std::vector<std::vector<int>>& series1, std::vector<std::vector<int>>& series2);
        void test() override;
    };
}

#endif //ALGORITHM_AGGREGATETWOTIMESERIES_H
