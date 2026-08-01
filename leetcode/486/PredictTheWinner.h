//
// Created by Ruiguo on 1/8/2026.
//

#ifndef ALGORITHM_PREDICTTHEWINNER_H
#define ALGORITHM_PREDICTTHEWINNER_H

#include "../Base.h"

namespace leetcode {
    class PredictTheWinner: public Base {
    public:
        bool predictTheWinner(std::vector<int>& nums);
        void test() override;
    };
}

#endif //ALGORITHM_PREDICTTHEWINNER_H
