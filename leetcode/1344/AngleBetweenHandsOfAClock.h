//
// Created by ruiguo on 2026/6/18.
//

#ifndef ALGORITHM_ANGLEBETWEENHANDSOFACLOCK_H
#define ALGORITHM_ANGLEBETWEENHANDSOFACLOCK_H

#include "../Base.h"

namespace leetcode {
    class AngleBetweenHandsOfAClock: public Base {
    public:
        double angleClock(int hour, int minutes);
        void test() override;
    };
}


#endif //ALGORITHM_ANGLEBETWEENHANDSOFACLOCK_H
