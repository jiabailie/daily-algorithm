//
// Created by Ruiguo Yang on 2026/4/19.
//

#ifndef ALGORITHM_MULTISOURCEFLOODFILL_H
#define ALGORITHM_MULTISOURCEFLOODFILL_H

#include <vector>
#include "../Base.h"

namespace leetcode {
    class MultiSourceFloodFill: public Base {
    public:
        static constexpr int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        std::vector<std::vector<int>> colorGrid1(int n, int m, std::vector<std::vector<int>>& sources);
        std::vector<std::vector<int>> colorGrid2(int n, int m, std::vector<std::vector<int>>& sources);
        void test() override;
    };
}


#endif //ALGORITHM_MULTISOURCEFLOODFILL_H