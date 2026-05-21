//
// Created by Ruiguo Yang on 2026/5/21.
//

#ifndef ALGORITHM_FINDTHELENGTHOFTHELONGESTCOMMONPREFIX_H
#define ALGORITHM_FINDTHELENGTHOFTHELONGESTCOMMONPREFIX_H

#include "../Base.h"

namespace leetcode {
    class FindTheLengthOfTheLongestCommonPrefix: public Base{
    public:
        int longestCommonPrefix1(std::vector<int>& arr1, std::vector<int>& arr2);
        int longestCommonPrefix2(std::vector<int>& arr1, std::vector<int>& arr2);
        void test() override;
    };
}



#endif //ALGORITHM_FINDTHELENGTHOFTHELONGESTCOMMONPREFIX_H