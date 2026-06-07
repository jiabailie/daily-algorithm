//
// Created by Ruiguo Yang on 2026/6/7.
//

#ifndef ALGORITHM_TREENODE_H
#define ALGORITHM_TREENODE_H

namespace leetcode::common {
    // Definition for a binary tree node.
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
}

#endif //ALGORITHM_TREENODE_H