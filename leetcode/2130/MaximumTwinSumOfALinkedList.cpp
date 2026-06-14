//
// Created by Ruiguo Yang on 2026/6/14.
//

#include "MaximumTwinSumOfALinkedList.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    common::ListNode *MaximumTwinSumOfALinkedList::middleNode(common::ListNode *head) {
        common::ListNode *slow = head;
        common::ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    common::ListNode *MaximumTwinSumOfALinkedList::reverseList(common::ListNode *head) {
        common::ListNode * pre = nullptr;
        common::ListNode * cur = head;
        while (cur) {
            common::ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    int MaximumTwinSumOfALinkedList::pairSum(common::ListNode *head1) {
        common::ListNode *middle = middleNode(head1);
        common::ListNode *head2 = reverseList(middle);

        int ans = 0;
        while (head2) {
            ans = std::max(ans, head1->val + head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }
        return ans;
    }

    void MaximumTwinSumOfALinkedList::test() {
        std::vector<std::vector<int>> nums {
            {5,4,2,1},
            {4,2,2,3},
            {1,100000}
        };
        std::vector<int> expect {6,7,100001};
        for (int i = 0; i < expect.size(); i++) {
            common::ListNode *head = common::buildList(nums[i]);

            int actual = pairSum(head);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;

            common::delList(head);
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2130", leetcode::MaximumTwinSumOfALinkedList);