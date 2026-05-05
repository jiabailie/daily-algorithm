//
// Created by Ruiguo Yang on 2026/5/5.
//

#ifndef ALGORITHM_ROTATELIST_H
#define ALGORITHM_ROTATELIST_H

#include "../Base.h"
#include "../common/ListNode.h"

namespace leetcode {
    class RotateList: public Base{
    public:
        common::ListNode* buildListNode(std::vector<int>& nums);
        common::ListNode* rotateRight(common::ListNode* head, int k);
        void test() override;
    };
}


#endif //ALGORITHM_ROTATELIST_H