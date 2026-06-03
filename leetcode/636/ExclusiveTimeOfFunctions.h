//
// Created by Ruiguo Yang on 2026/6/3.
//

#ifndef ALGORITHM_EXCLUSIVETIMEOFFUNCTIONS_H
#define ALGORITHM_EXCLUSIVETIMEOFFUNCTIONS_H

#include "../Base.h"

namespace leetcode {
    class ExclusiveTimeOfFunctions: public Base {
    public:
        std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs);
        void test() override;
    };
}

#endif //ALGORITHM_EXCLUSIVETIMEOFFUNCTIONS_H