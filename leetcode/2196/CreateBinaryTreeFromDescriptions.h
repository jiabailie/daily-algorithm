//
// Created by Ruiguo Yang on 2026/6/7.
//

#ifndef ALGORITHM_CREATEBINARYTREEFROMDESCRIPTIONS_H
#define ALGORITHM_CREATEBINARYTREEFROMDESCRIPTIONS_H

#include "../Base.h"
#include "leetcode/common/TreeNode.h"

namespace leetcode {
    class CreateBinaryTreeFromDescriptions: public Base {
    public:
        bool isEqual(common::TreeNode *t1, common::TreeNode *t2);
        std::vector<int> preorderTraverse(common::TreeNode *root);
        common::TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions);
        void test() override;
    };
}

#endif //ALGORITHM_CREATEBINARYTREEFROMDESCRIPTIONS_H