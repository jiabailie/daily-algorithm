//
// Created by Ruiguo Yang on 2026/6/13.
//

#include "WeightedWordMapping.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::string WeightedWordMapping::mapWordWeights(std::vector<std::string> &words, std::vector<int> &weights) {
        std::string ans;
        for (std::string& w: words) {
            int weight = 0;
            for (char c: w) {
                weight += weights[c - 'a'];
            }
            char m = (char)('z' - (weight % 26));
            ans.push_back(m);
        }
        return ans;
    }

    void WeightedWordMapping::test() {
        std::vector<std::vector<std::string>> words {
            {"abcd","def","xyz"},
            {"a","b","c"},
            {"abcd"}
        };
        std::vector<std::vector<int>> weights {
            {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5}
        };
        std::vector<std::string> expect {
            "rij",
            "yyy",
            "g"
        };
        for (int i = 0; i < expect.size(); i++) {
            std::string actual = mapWordWeights(words[i], weights[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3838", leetcode::WeightedWordMapping);