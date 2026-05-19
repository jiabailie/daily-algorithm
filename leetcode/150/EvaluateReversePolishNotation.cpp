//
// Created by Ruiguo Yang on 2026/5/19.
//

#include "EvaluateReversePolishNotation.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    bool EvaluateReversePolishNotation::isOperator(const std::string &s) {
        if (s.size() != 1) {
            return false;
        }

        if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
            return true;
        }

        return false;
    }

    int EvaluateReversePolishNotation::strToInt(const std::string &s) {
        int sign = 1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 && s[i] == '-') {
                sign = -1;
                continue;
            }
            ans = ans * 10 + (s[i] - '0');
        }
        return (sign * ans);
    }

    int EvaluateReversePolishNotation::evalRPN(const std::vector<std::string> &tokens) {
        std::vector<int> stk;
        for (const std::string& t: tokens) {
            if (!isOperator(t)) {
                stk.push_back(strToInt(t));
                continue;
            }

            int oper2 = stk.back();
            stk.pop_back();
            int oper1 = stk.back();
            stk.pop_back();

            int oper = 0;
            switch (t[0]) {
                case '+':
                    oper = oper1 + oper2;
                    break;
                case '-':
                    oper = oper1 - oper2;
                    break;
                case '*':
                    oper = oper1 * oper2;
                    break;
                case '/':
                    oper = oper1 / oper2;
                    break;
                default:
                    break;
            }
            stk.push_back(oper);
        }
        return stk[0];
    }

    void EvaluateReversePolishNotation::test() {
        std::vector<std::vector<std::string>> tokens {
            {"2","1","+","3","*"},
            {"4","13","5","/","+"},
            {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}
        };
        std::vector<int> expect {9,6,22};
        for (int i = 0; i < expect.size(); i++) {
            int actual = evalRPN(tokens[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("150", leetcode::EvaluateReversePolishNotation);