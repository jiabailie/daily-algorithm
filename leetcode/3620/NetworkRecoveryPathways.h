//
// Created by ruiguo on 2026/7/3.
//

#ifndef ALGORITHM_NETWORKRECOVERYPATHWAYS_H
#define ALGORITHM_NETWORKRECOVERYPATHWAYS_H

#include "../Base.h"

namespace leetcode {
    class NetworkRecoveryPathways: public Base {
    public:
        int findMaxPathScore(std::vector<std::vector<int>>& edges, std::vector<bool>& online, long long k);
        void test() override;
    };
}

#endif //ALGORITHM_NETWORKRECOVERYPATHWAYS_H
