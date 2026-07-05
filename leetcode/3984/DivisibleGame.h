//
// Created by Ruiguo Yang on 2026/7/5.
//

#ifndef ALGORITHM_DIVISIBLEGAME_H
#define ALGORITHM_DIVISIBLEGAME_H

#include "../Base.h"

namespace leetcode {
    constexpr int MX = 1'000'001;
    std::vector<int> primeDivisors[MX];
    int initPrimeDisivisors = [] {
        for (int i = 2; i < MX; ++i) {
            if (primeDivisors[i].empty()) {
                for (int j = i; j < MX; j += i) {
                    primeDivisors[j].push_back(i);
                }
            }
        }
        return 0;
    }();
    class DivisibleGame: public Base {
    private:
        int maxSubArray(std::vector<int>& nums, int k);
    public:
        int divisibleGame(std::vector<int>& nums);
        void test() override;
    };

}

#endif //ALGORITHM_DIVISIBLEGAME_H