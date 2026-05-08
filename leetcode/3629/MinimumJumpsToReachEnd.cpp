//
// Created by Ruiguo Yang on 2026/5/8.
//

#include "MinimumJumpsToReachEnd.h"

#include <iostream>

namespace leetcode {
    std::vector<std::vector<int> > MinimumJumpsToReachEnd::getPrimeFactors() {
        constexpr int CEILING = 1'000'001;
        std::vector<std::vector<int>> factors(CEILING);
        for (int i = 2; i < CEILING; ++i) {
            if (!factors[i].empty()) {
                continue;
            }
            for (int j = i; j < CEILING; j += i) {
                factors[j].push_back(i);
            }
        }
        return factors;
    }

    int MinimumJumpsToReachEnd::minJumps(std::vector<int> &nums) {
        std::vector<std::vector<int>> primeFactors = getPrimeFactors();

        int n = nums.size();
        std::unordered_map<int, std::vector<int>> index;
        for (int i = 0; i < n; ++i) {
            for (int p: primeFactors[nums[i]]) {
                index[p].push_back(i);
            }
        }

        int ans = 0;
        std::vector<bool> vis(n, false);
        vis[0] = true;
        std::vector<int> q = {0};

        while (true) {
            std::vector<int> tmp = q;
            q.clear();
            for (int i: tmp) {
                if (i == n - 1) {
                    return ans;
                }

                auto& idx = index[nums[i]];
                idx.push_back(i + 1);
                if (i > 0) {
                    idx.push_back(i - 1);
                }

                for (int j: idx) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push_back(j);
                    }
                }
                idx.clear();
            }
            ans++;
        }
        return ans;
    }

    void MinimumJumpsToReachEnd::test() {
        std::vector<std::vector<int>> nums {
            {1,2,4,6},
            {2,3,4,7,9},
            {4,6,5,8}
        };
        std::vector<int> expect {2,2,3};
        for (int i = 0; i < expect.size(); ++i) {
            int actual = minJumps(nums[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3629", leetcode::MinimumJumpsToReachEnd);
