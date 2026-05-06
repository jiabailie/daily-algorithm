//
// Created by Ruiguo Yang on 2026/5/6.
//

#ifndef ALGORITHM_ROTATINGTHEBOX_H
#define ALGORITHM_ROTATINGTHEBOX_H

#include "../Base.h"

namespace leetcode {
    class RotatingTheBox: public Base {
    public:
        std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& boxGrid);
        void test() override;
    };
}


#endif //ALGORITHM_ROTATINGTHEBOX_H
