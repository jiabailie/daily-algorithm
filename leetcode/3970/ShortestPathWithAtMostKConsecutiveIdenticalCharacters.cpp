//
// Created by ruiguo on 2026/6/22.
//

#include "ShortestPathWithAtMostKConsecutiveIdenticalCharacters.h"

#include <climits>
#include <iostream>
#include <ostream>
#include <queue>
#include <tuple>

namespace leetcode {
    int ShortestPathWithAtMostKConsecutiveIdenticalCharacters::shortestPath(int n, std::vector<std::vector<int> > &edges, std::string labels, int k) {
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for (auto& e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }

        std::vector<std::vector<int>> dis(n, std::vector<int>(k + 1, INT_MAX));
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> h;

        auto add = [&](int x, int cnt, int d) -> void {
            if (d < dis[x][cnt]) {
                dis[x][cnt] = d;
                h.emplace(d, x, cnt);
            }
        };

        add(0, 1, 0);

        while (!h.empty()) {
            auto [d, x, cnt] = h.top();
            h.pop();
            if (x == n - 1) {
                return d;
            }

            if (d > dis[x][cnt]) {
                continue;
            }

            for (auto& [y, w]: g[x]) {
                if (labels[y] != labels[x]) {
                    add(y, 1, d + w);
                } else if (cnt + 1 <= k) {
                    add(y, cnt + 1, d + w);
                }
            }
        }

        return -1;
    }

    void ShortestPathWithAtMostKConsecutiveIdenticalCharacters::test() {
        std::vector<int> n {3,3,3};
        std::vector<std::vector<std::vector<int>>> edges {
            {{0,1,1},{1,2,1},{0,2,3}},
            {{0,1,1},{1,2,1},{0,2,3}},
            {{0,1,1},{1,2,1}}
        };
        std::vector<std::string> labels {"aab", "aab", "aaa"};
        std::vector<int> k {1,2,2};
        std::vector<int> expect {3,2,-1};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = shortestPath(n[i], edges[i], labels[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3970", leetcode::ShortestPathWithAtMostKConsecutiveIdenticalCharacters);