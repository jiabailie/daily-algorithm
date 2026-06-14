//
// Created by Ruiguo Yang on 2026/5/5.
//

#include "RotateList.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    common::ListNode *RotateList::rotateRight(common::ListNode *head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        int length = 1;
        common::ListNode* tail = head;
        while (tail->next != nullptr) {
            length++;
            tail = tail->next;
        }
        k %= length;

        tail->next = head;

        common::ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }

        common::ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }

    void RotateList::test() {
        std::vector<std::vector<int>> nums {
            {1,2,3,4,5},
            {0,1,2},
            {1,2},
            {1,2},
            {1,2,3}
        };
        std::vector<int> ks {2,4,2,3,2000000000};
        std::vector<std::vector<int>> expect {
            {4,5,1,2,3},
            {2,0,1},
            {1,2},
            {2,1},
            {2,3,1}
        };
        for (int i = 0; i < expect.size(); ++i) {
            common::ListNode* head = common::buildList(nums[i]);
            common::ListNode* actualList = rotateRight(head, ks[i]);

            std::vector<int> actual;
            common::ListNode* actualHead = actualList;
            while (actualHead != nullptr) {
                actual.push_back(actualHead->val);
                actualHead = actualHead->next;
            }

            bool isEqual = expect[i].size() == actual.size();
            for (int j = 0; isEqual && j < expect[i].size(); ++j) {
                if (expect[i][j] != actual[j]) {
                    isEqual = false;
                }
            }

            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;

            common::delList(head);
            common::delList(actualHead);
        }
    }
}

REGISTER_LEETCODE_SOLUTION("61", leetcode::RotateList);