//
// Created by Ruiguo Yang on 2026/6/14.
//

#ifndef ALGORITHM_MAXIMUMTWINSUMOFALINKEDLIST_H
#define ALGORITHM_MAXIMUMTWINSUMOFALINKEDLIST_H

#include "../Base.h"
#include "leetcode/common/ListNode.h"

namespace leetcode {
    class MaximumTwinSumOfALinkedList: public Base {
    public:
        common::ListNode* middleNode(common::ListNode* head);
        common::ListNode* reverseList(common::ListNode* head);
        int pairSum(common::ListNode* head1);
        void test() override;
    };
}

#endif //ALGORITHM_MAXIMUMTWINSUMOFALINKEDLIST_H