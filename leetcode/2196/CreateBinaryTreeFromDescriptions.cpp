//
// Created by Ruiguo Yang on 2026/6/7.
//

#include "CreateBinaryTreeFromDescriptions.h"

#include <iostream>
#include <ostream>
#include <queue>

namespace leetcode {
    bool CreateBinaryTreeFromDescriptions::isEqual(common::TreeNode *t1, common::TreeNode *t2) {
        if ((!t1 && t2) || (t1 && !t2)) { return false; }
        if (!t1 && !t2) { return true; }
        if (t1->val != t2->val) { return false; }
        return (isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right));
    }

    std::vector<int> CreateBinaryTreeFromDescriptions::preorderTraverse(common::TreeNode *root) {
        std::vector<int> res;

        if (root == nullptr) { return res; }

        std::queue<common::TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            common::TreeNode *node = que.front();
            que.pop();

            res.push_back(node->val);
            if (node->left != nullptr) { que.push(node->left); }
            if (node->right != nullptr) { que.push(node->right); }
        }

        return res;
    }

    common::TreeNode *CreateBinaryTreeFromDescriptions::createBinaryTree(std::vector<std::vector<int> > &descriptions) {
        std::unordered_map<int, int> parents;
        std::unordered_map<int, int> leftChild;
        std::unordered_map<int, int> rightChild;
        for (auto& d: descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            parents[child] = parent;
            if (isLeft) {
                leftChild[parent] = child;
            } else {
                rightChild[parent] = child;
            }
        }

        std::unordered_map<int, common::TreeNode*> nodes;

        for (auto [parent, child] : leftChild) {
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new common::TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new common::TreeNode(child);
            }
            nodes[parent]->left = nodes[child];
        }

        for (auto [parent, child] : rightChild) {
            if (nodes.find(parent) == nodes.end()) {
                nodes[parent] = new common::TreeNode(parent);
            }
            if (nodes.find(child) == nodes.end()) {
                nodes[child] = new common::TreeNode(child);
            }
            nodes[parent]->right = nodes[child];
        }

        common::TreeNode* root = nullptr;
        for (auto& [k, _]: nodes) {
            if (parents.find(k) == parents.end()) {
                root = nodes[k];
                break;
            }
        }
        return root;
    }

    void CreateBinaryTreeFromDescriptions::test() {
        std::vector<std::vector<std::vector<int>>> descriptions {
            {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}},
            {{1,2,1},{2,3,0},{3,4,1}}
        };
        std::vector<std::vector<int>> expect {
            {50,20,80,15,17,19},
            {1,2,3,4}
        };
        for (int i = 0; i < expect.size(); i++) {
            common::TreeNode *root = createBinaryTree(descriptions[i]);
            std::vector<int> actual = preorderTraverse(root);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2196", leetcode::CreateBinaryTreeFromDescriptions);