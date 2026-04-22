//
// Created by Ruiguo Yang on 2026/4/22.
//

#include <iostream>
#include "WordsWithinTwoEditsOfDictionary.h"

namespace leetcode {
    std::vector<std::string> WordsWithinTwoEditsOfDictionary::twoEditWords(std::vector<std::string> &queries, std::vector<std::string> &dictionary) {
        std::vector<std::string> ans;
        for (const std::string& q: queries) {
            for (const std::string& d: dictionary) {
                if (q.size() != d.size()) {
                    continue;
                }

                int dis = 0;
                for (int i = 0; i < q.size(); ++i) {
                    if (q[i] != d[i]) {
                        dis++;
                    }
                }

                if (dis <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }

    void WordsWithinTwoEditsOfDictionary::test() {
        std::vector<std::vector<std::string>> queries {
            {"word","note","ants","wood"},
            {"yes"}
        };
        std::vector<std::vector<std::string>> dictionaries {
            {"wood","joke","moat"},
            {"not"}
        };
        std::vector<std::vector<std::string>> expect {
            {"word","note","wood"},
            {}
        };
        for (int i = 0; i < expect.size(); ++i) {
            std::vector<std::string> actual = twoEditWords(queries[i], dictionaries[i]);
            if (actual.size() != expect[i].size()) {
                std::cout << "FAIL" << std::endl;
                continue;
            }

            bool isEqual = true;
            for (int j = 0; j < actual.size() && isEqual; ++j) {
                if (actual[j] != expect[i][j]) {
                    isEqual = false;
                }
            }
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("2452", leetcode::WordsWithinTwoEditsOfDictionary);