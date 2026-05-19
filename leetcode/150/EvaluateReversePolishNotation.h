//
// Created by Ruiguo Yang on 2026/5/19.
//

#ifndef ALGORITHM_EVALUATEREVERSEPOLISHNOTATION_H
#define ALGORITHM_EVALUATEREVERSEPOLISHNOTATION_H

#include "../Base.h"

namespace leetcode {
    class EvaluateReversePolishNotation: public Base {
    public:
        bool isOperator(const std::string& s);
        int strToInt(const std::string& s);
        int evalRPN(const std::vector<std::string>& tokens);
        void test() override;
    };
}



#endif //ALGORITHM_EVALUATEREVERSEPOLISHNOTATION_H