//
// Created by Ruiguo Yang on 2026/5/18.
//

#include "JumpGameIV.h"

#include <iostream>
#include <ostream>
#include <unordered_map>

namespace leetcode {
    int JumpGameIV::minJumps(std::vector<int> &arr) {
        int n = arr.size();
        if (n == 1) { return 0; }

        std::unordered_map<int, std::vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[arr[i]].push_back(i);
        }

        std::vector<int> v(n, false);
        v[0] = true;

        int curr = 0, next = 1;
        std::vector<int> q[2];
        q[curr].push_back(0);

        int ans = 0;
        for (; !v[n - 1]; ++ans) {
            q[next].clear();
            for (int j: q[curr]) {
                if (j - 1 >= 0 && !v[j - 1]) {
                    v[j - 1] = true;
                    q[next].push_back(j - 1);
                }
                if (j + 1 < n && !v[j + 1]) {
                    v[j + 1] = true;
                    q[next].push_back(j + 1);
                }
                for (int p: pos[arr[j]]) {
                    if (v[p]) { continue; }
                    v[p] = true;
                    q[next].push_back(p);
                }
                pos.erase(arr[j]);
            }
            curr = next;
            next = 1 - next;
        }
        return ans;
    }

    void JumpGameIV::test() {
        std::vector<std::vector<int>> arrs {
            {100,-23,-23,404,100,23,23,23,3,404},
            {7},
            {7,6,9,6,9,6,9,7}
        };
        std::vector<int> expect {3,0,1};
        for (int i = 0; i < expect.size(); i++) {
            int actual = minJumps(arrs[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("1345", leetcode::JumpGameIV);
