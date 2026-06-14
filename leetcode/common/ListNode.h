//
// Created by Ruiguo Yang on 2026/5/5.
//

#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H

#include <vector>


namespace leetcode::common {
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
    };

    inline ListNode* buildList(const std::vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) {
            return nullptr;
        }

        ListNode* head = new ListNode(nums[0]);
        ListNode* cursor = head;
        for (int i = 1; i < n; ++i) {
            ListNode* next = new ListNode(nums[i]);
            cursor->next = next;
            cursor = next;
        }
        return head;
    }

    inline void delList(ListNode* head) {
        while (head) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
}

#endif //ALGORITHM_LISTNODE_H
