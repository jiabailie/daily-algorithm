//
// Created by ruiguo on 2026/8/26.
//

#ifndef ALGORITHM_SHORTESTANDLEXICOGRAPHICALLYSMALLESTBEAUTIFULSTRING_H
#define ALGORITHM_SHORTESTANDLEXICOGRAPHICALLYSMALLESTBEAUTIFULSTRING_H

#include "../Base.h"

namespace leetcode {
    class ShortestAndLexicographicallySmallestBeautifulString: public Base {
    public:
        int compare(std::string& a, std::string& b);
        std::string shortestBeautifulSubstring(std::string s, int k);
        void test() override;
    };
}

#endif //ALGORITHM_SHORTESTANDLEXICOGRAPHICALLYSMALLESTBEAUTIFULSTRING_H
