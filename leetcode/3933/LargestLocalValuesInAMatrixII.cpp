//
// Created by Ruiguo Yang on 2026/5/17.
//

#include "LargestLocalValuesInAMatrixII.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    int LargestLocalValuesInAMatrixII::countLocalMaximums(std::vector<std::vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        std::vector<std::vector<std::vector<int>>> b(n, std::vector<std::vector<int>>(m, std::vector<int>(m, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cm = 0;
                for (int k = j; k < m; ++k) {
                    cm = std::max(cm, matrix[i][k]);
                    b[i][j][k] = cm;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = matrix[i][j];
                if (x == 0) { continue; }

                bool f = true;
                int minR = std::max(0, i - x);
                int maxR = std::min(n - 1, i + x);
                int minC = std::max(0, j - x);
                int maxC = std::min(m - 1, j + x);

                for (int r = minR; r <= maxR; ++r) {
                    int disR = std::abs(i - r);

                    if (disR == x) {
                        int s = std::max(0, j - x + 1);
                        int e = std::min(m - 1, j + x - 1);
                        if (s <= e) {
                            if (b[r][s][e] > x) {
                                f = false;
                                break;
                            }
                        }
                    } else {
                        if (b[r][minC][maxC] > x) {
                            f = false;
                            break;
                        }
                    }
                }

                if (f) {
                    ans++;
                }
            }
        }
        return ans;
    }

    void LargestLocalValuesInAMatrixII::test() {
        std::vector<std::vector<std::vector<int>>> matrix {
            {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,2,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}},
            {{1,2},{3,4}},
            {{1,0,1},{0,1,0},{1,0,1}},
            {{1,1},{1,1}}
        };
        std::vector<int> expect {1,1,5,4};
        for (int i = 0; i < expect.size(); i++) {
            int actual = countLocalMaximums(matrix[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3933", leetcode::LargestLocalValuesInAMatrixII);