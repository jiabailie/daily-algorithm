//
// Created by Ruiguo Yang on 2026/5/22.
//

#ifndef ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H
#define ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H

#include "../Base.h"

namespace leetcode {
    class SearchInRotatedSortedArray: public Base {
    public:
        int search(std::vector<int>& nums, int target);
        void test() override;
    };
}



#endif //ALGORITHM_SEARCHINROTATEDSORTEDARRAY_H