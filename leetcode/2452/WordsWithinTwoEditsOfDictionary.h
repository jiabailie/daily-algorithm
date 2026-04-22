//
// Created by Ruiguo Yang on 2026/4/22.
//

#ifndef ALGORITHM_WORDSWITHINTWOEDITSOFDICTIONARY_H
#define ALGORITHM_WORDSWITHINTWOEDITSOFDICTIONARY_H

#include <cstring>
#include <vector>
#include "../Base.h"

namespace leetcode {
    class WordsWithinTwoEditsOfDictionary: public Base {
    public:
        std::vector<std::string> twoEditWords(std::vector<std::string>& queries, std::vector<std::string>& dictionary);
        void test() override;
    };
}



#endif //ALGORITHM_WORDSWITHINTWOEDITSOFDICTIONARY_H