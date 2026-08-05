//
// Created by Ruiguo on 5/8/2026.
//

#ifndef ALGORITHM_REMOVEMETHODSFROMPROJECT_H
#define ALGORITHM_REMOVEMETHODSFROMPROJECT_H

#include "../Base.h"

namespace leetcode {
    class RemoveMethodsFromProject: public Base {
    public:
        std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations);
        void test() override;
    };
}

#endif //ALGORITHM_REMOVEMETHODSFROMPROJECT_H
