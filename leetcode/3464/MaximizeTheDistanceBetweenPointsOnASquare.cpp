//
// Created by Ruiguo Yang on 2026/4/25.
//

#include "MaximizeTheDistanceBetweenPointsOnASquare.h"

#include <algorithm>
#include <iostream>

namespace leetcode {
    int MaximizeTheDistanceBetweenPointsOnASquare::maxDistance(int side, std::vector<std::vector<int> > &points, int k) {
        std::vector<long long> a;
        for (auto& p: points) {
            int x = p[0];
            int y = p[1];
            if (x == 0) {
                a.push_back(y);
            } else if (y == side) {
                a.push_back(side + x);
            } else if (x == side) {
                a.push_back(side * 3LL - y);
            } else {
                a.push_back(side * 4LL - x);
            }
        }

        std::sort(a.begin(), a.end());

        auto check = [&](int low) -> bool {
            for (long long start: a) {
                long long end = start + side * 4LL - low;
                long long cur = start;
                for (int i = 0; i < k - 1; ++i) {
                    auto it = std::lower_bound(a.begin(), a.end(), cur + low);
                    if (it == a.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }

                if (cur >= 0) {
                    return true;
                }
            }
            return false;
        };

        int left = 1;
        int right = side * 4LL / k + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }

    void MaximizeTheDistanceBetweenPointsOnASquare::test() {
        std::vector<int> sides { 2, 2, 2 };
        std::vector<std::vector<std::vector<int>>> points {
            {{0,2},{2,0},{2,2},{0,0}},
            {{0,0},{1,2},{2,0},{2,2},{2,1}},
            {{0,0},{0,1},{0,2},{1,2},{2,0},{2,2},{2,1}}
        };
        std::vector<int> ks {4,4,5};
        std::vector<int> expect {2,1,1};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = maxDistance(sides[i], points[i], ks[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3464", leetcode::MaximizeTheDistanceBetweenPointsOnASquare);