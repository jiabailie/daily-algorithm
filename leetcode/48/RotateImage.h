//
// Created by Ruiguo Yang on 2026/5/4.
//

#ifndef ALGORITHM_ROTATEIMAGE_H
#define ALGORITHM_ROTATEIMAGE_H

#include "../Base.h"

namespace leetcode {
    class RotateImage: public Base {
    public:
        void rotate(std::vector<std::vector<int>>& matrix);
        void test() override;
    };
}


#endif //ALGORITHM_ROTATEIMAGE_H