//
// Created by Ruiguo Yang on 2026/5/6.
//

#include "RotatingTheBox.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    std::vector<std::vector<char> > RotatingTheBox::rotateTheBox(std::vector<std::vector<char> > &boxGrid) {
        int h = boxGrid.size();
        int w = boxGrid[0].size();

        std::vector<std::vector<char>> ans(w, std::vector<char>(h));

        // move row i (from 0 to h) to col (h - 1 - i)
        for (int i = 0; i < h; ++i) {
            int y = h - 1 - i;
            for (int x = w - 1; x >= 0; --x) {
                ans[x][y] = boxGrid[i][x];
            }
        }

        for (int i = w - 2; i >= 0; --i) {
            for (int j = 0; j < h; ++j) {
                int x = i;
                while (x + 1 < w && ans[x][j] == '#' && ans[x + 1][j] == '.') {
                    ans[x][j] = '.';
                    ans[x + 1][j] = '#';
                    x++;
                }
            }
        }

        return ans;
    }

    void RotatingTheBox::test() {
        std::vector<std::vector<std::vector<char>>> boxGrids {
            {{'#','.','#'}},
            {{'#','.','*','.'},{'#','#','*','.'}},
            {{'#','#','*','.','*','.'},{'#','#','#','*','.','.'},{'#','#','#','.','#','.'}}
        };
        std::vector<std::vector<std::vector<char>>> expect {
            {{'.'}, {'#'}, {'#'}},
            {{'#','.'},{'#','#'},{'*','*'},{'.','.'}},
            {{'.','#','#'},{'.','#','#'},{'#','#','*'},{'#','*','.'},{'#','.','*'},{'#','.','.'}}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector actual = rotateTheBox(boxGrids[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("1861", leetcode::RotatingTheBox);