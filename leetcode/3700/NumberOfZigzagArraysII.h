//
// Created by ruiguo on 2026/6/24.
//

#ifndef ALGORITHM_NUMBEROFZIGZAGARRAYSII_H
#define ALGORITHM_NUMBEROFZIGZAGARRAYSII_H

#include "../Base.h"

namespace leetcode {
    constexpr int MOD = 1'000'000'007;
    class NumberOfZigzagArraysII: public Base {
    private:
        using matrix = std::vector<std::vector<long long>>;
        matrix mul(matrix& a, matrix& b);
        matrix pow_mul(matrix a, int n, matrix& f1);
    public:
        int zigZagArrays(int n, int l, int r);
        void test() override;
    };
}

#endif //ALGORITHM_NUMBEROFZIGZAGARRAYSII_H
