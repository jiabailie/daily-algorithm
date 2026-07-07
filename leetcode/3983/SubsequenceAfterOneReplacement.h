//
// Created by ruiguo on 2026/7/7.
//

#ifndef ALGORITHM_SUBSEQUENCEAFTERONEREPLACEMENT_H
#define ALGORITHM_SUBSEQUENCEAFTERONEREPLACEMENT_H

#include "../Base.h"

namespace leetcode {
    class SubsequenceAfterOneReplacement: public Base {
    public:
        bool canMakeSubsequence(std::string s, std::string t);
        void test() override;
    };
}

#endif //ALGORITHM_SUBSEQUENCEAFTERONEREPLACEMENT_H
