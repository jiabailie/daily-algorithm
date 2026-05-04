//
// Created by Ruiguo Yang on 2026/5/4.
//

#include "RotateImage.h"
#include <iostream>

namespace leetcode {
    void RotateImage::rotate(std::vector<std::vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int c = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = c;
            }
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void RotateImage::test() {
        std::vector<std::vector<std::vector<int>>> matrixs {
            {{1,2,3},{4,5,6},{7,8,9}},
            {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
        };
        std::vector<std::vector<std::vector<int>>> expect {
            {{7,4,1},{8,5,2},{9,6,3}},
            {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}
        };
        for (int i = 0; i <expect.size(); i++) {
            rotate(matrixs[i]);

            int n = matrixs[i].size();
            bool isEqual = true;
            for (int j = 0; j < n && isEqual; ++j) {
                for (int k = 0; k < n && isEqual; ++k) {
                    if (matrixs[i][j][k] != expect[i][j][k]) {
                        isEqual = false;
                    }
                }
            }

            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("48", leetcode::RotateImage);
