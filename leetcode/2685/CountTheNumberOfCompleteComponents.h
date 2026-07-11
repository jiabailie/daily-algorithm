//
// Created by Ruiguo on 11/7/2026.
//

#ifndef ALGORITHM_COUNTTHENUMBEROFCOMPLETECOMPONENTS_H
#define ALGORITHM_COUNTTHENUMBEROFCOMPLETECOMPONENTS_H

#include "../Base.h"

namespace leetcode {
    class CountTheNumberOfCompleteComponents: public Base {
    public:
        int countCompleteComponents(int n, std::vector<std::vector<int>>& edges);
        void test() override;
    };
}

#endif //ALGORITHM_COUNTTHENUMBEROFCOMPLETECOMPONENTS_H
