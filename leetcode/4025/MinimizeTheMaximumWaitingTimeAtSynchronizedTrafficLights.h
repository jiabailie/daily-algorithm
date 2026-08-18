//
// Created by ruiguo on 2026/8/18.
//

#ifndef ALGORITHM_MINIMIZETHEMAXIMUMWAITINGTIMEATSYNCHRONIZEDTRAFFICLIGHTS_H
#define ALGORITHM_MINIMIZETHEMAXIMUMWAITINGTIMEATSYNCHRONIZEDTRAFFICLIGHTS_H

#include "../Base.h"

namespace leetcode {
    class MinimizeTheMaximumWaitingTimeAtSynchronizedTrafficLights: public Base {
    public:
        int minPenalty(int period, std::vector<int>& lights, std::vector<int>& arrivalTime);
        void test() override;
    };
}

#endif //ALGORITHM_MINIMIZETHEMAXIMUMWAITINGTIMEATSYNCHRONIZEDTRAFFICLIGHTS_H
