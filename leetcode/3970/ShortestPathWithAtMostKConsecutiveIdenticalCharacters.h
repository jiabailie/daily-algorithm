//
// Created by ruiguo on 2026/6/22.
//

#ifndef ALGORITHM_SHORTESTPATHWITHATMOSTKCONSECUTIVEIDENTICALCHARACTERS_H
#define ALGORITHM_SHORTESTPATHWITHATMOSTKCONSECUTIVEIDENTICALCHARACTERS_H

#include "../Base.h"

namespace leetcode {
    class ShortestPathWithAtMostKConsecutiveIdenticalCharacters: public Base {
    public:
        int shortestPath(int n, std::vector<std::vector<int>>& edges, std::string labels, int k);
        void test() override;
    };
}

#endif //ALGORITHM_SHORTESTPATHWITHATMOSTKCONSECUTIVEIDENTICALCHARACTERS_H
