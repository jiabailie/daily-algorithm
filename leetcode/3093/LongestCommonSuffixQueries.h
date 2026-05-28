//
// Created by Ruiguo Yang on 2026/5/28.
//

#ifndef ALGORITHM_LONGESTCOMMONSUFFIXQUERIES_H
#define ALGORITHM_LONGESTCOMMONSUFFIXQUERIES_H

#include "../Base.h"
#include <climits>

namespace leetcode {
    struct Node {
        Node* child[26]{};
        int minLen = INT_MAX;
        int shortestIndex;
    };
    class LongestCommonSuffixQueries: public Base {
    public:
        void clear(Node* node);
        std::vector<int> stringIndices(std::vector<std::string>& wordsContainer, std::vector<std::string>& wordsQuery);
        void test() override;
    };
}

#endif //ALGORITHM_LONGESTCOMMONSUFFIXQUERIES_H