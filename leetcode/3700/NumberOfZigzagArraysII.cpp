//
// Created by ruiguo on 2026/6/24.
//

#include "NumberOfZigzagArraysII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    NumberOfZigzagArraysII::matrix NumberOfZigzagArraysII::mul(matrix &a, matrix &b) {
        int n = a.size();
        int m = b[0].size();
        matrix c = matrix(n, std::vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[i].size(); ++k) {
                if (a[i][k] == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return c;
    }

    NumberOfZigzagArraysII::matrix NumberOfZigzagArraysII::pow_mul(matrix a, int n, matrix &f1) {
        matrix res = f1;
        while (n) {
            if (n & 1) {
                res = mul(a, res);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }

    int NumberOfZigzagArraysII::zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        matrix m(k * 2, std::vector<long long>(k * 2));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < i; ++j) {
                m[i][k + j] = 1;
            }
            for (int j = i + 1; j < k; ++j) {
                m[k + i][j] = 1;
            }
        }

        matrix f1(k * 2, std::vector<long long>(1, 1));
        matrix fn = pow_mul(m, n - 1, f1);

        long long ans = 0;
        for (auto& row: fn) {
            ans += row[0];
        }
        return ans % MOD;
    }

    void NumberOfZigzagArraysII::test() {
        std::vector<int> n {3,3};
        std::vector<int> l {4,1};
        std::vector<int> r {5,3};
        std::vector<int> expect {2,10};
        for (int i = 0; i < expect.size(); i++) {
            int actual = zigZagArrays(n[i], l[i], r[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3700", leetcode::NumberOfZigzagArraysII);