//
// Created by Ruiguo Yang on 2026/5/28.
//

#include "LongestCommonSuffixQueries.h"

#include <iostream>

namespace leetcode {
    void LongestCommonSuffixQueries::clear(Node *node) {
        for (int i = 0; i < 26; ++i) {
            if (node->child[i]) {
                clear(node->child[i]);
            }
        }
        delete node;
    }

    std::vector<int> LongestCommonSuffixQueries::stringIndices(std::vector<std::string> &wordsContainer, std::vector<std::string> &wordsQuery) {
        Node* root = new Node();
        for (int i = 0; i < wordsContainer.size(); i++) {
            std::string& s = wordsContainer[i];
            int len = s.size();
            if (len < root->minLen) {
                root->minLen = len;
                root->shortestIndex = i;
            }

            Node* cur = root;
            for (int j = len - 1; j >= 0; --j) {
                int b = s[j] - 'a';
                if (cur->child[b] == nullptr) {
                    cur->child[b] = new Node();
                }
                cur = cur->child[b];
                if (len < cur->minLen) {
                    cur->minLen = len;
                    cur->shortestIndex = i;
                }
            }
        }

        std::vector<int> ans;
        ans.reserve(wordsContainer.size());
        for (auto& s: wordsQuery) {
            Node* cur = root;
            for (int j = s.size() - 1; j >= 0 && cur->child[s[j] - 'a']; --j) {
                cur = cur->child[s[j] - 'a'];
            }
            ans.push_back(cur->shortestIndex);
        }

        clear(root);
        return ans;
    }

    void LongestCommonSuffixQueries::test() {
        std::vector<std::vector<std::string>> wordsContainer {
            {"abcd","bcd","xbcd"},
            {"abcdefgh","poiuygh","ghghgh"},
            {"kakfffk","fauafgkug","ffukkkafg"}
        };
        std::vector<std::vector<std::string>> wordsQuery {
            {"cd","bcd","xyz"},
            {"gh","acbfgh","acbfegh"},
            {"fkagag","kgaffaakfg","ukakkfua","ufauaff"}
        };
        std::vector<std::vector<int>> expect {
            {1,1,1},
            {2,0,2},
            {1,2,0,0}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = stringIndices(wordsContainer[i], wordsQuery[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3093", leetcode::LongestCommonSuffixQueries);