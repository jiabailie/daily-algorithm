//
// Created by Ruiguo Yang on 2026/6/10.
//

#include "MaximumTotalSubarrayValueII.h"
#include "../common/SparseTable.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    long long MaximumTotalSubarrayValueII::maxTotalValue(std::vector<int> &nums, int k) {
        int n = nums.size();

        using common::SparseTable;
        SparseTable st(nums);

        std::priority_queue<std::tuple<int, int, int>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(st.query(i, n), i, n);
        }

        long long ans = 0;
        while (k-- && std::get<0>(pq.top())) {
            auto [d, l, r] = pq.top();
            pq.pop();
            ans += d;
            pq.emplace(st.query(l, r - 1), l, r - 1);
        }
        return ans;
    }

    void MaximumTotalSubarrayValueII::test() {
        std::vector<std::vector<int>> nums {
            {1,3,2},
            {4,2,5,1}
        };
        std::vector<int> k {2,3};
        std::vector<long long> expect {4,12};
        for (int i = 0; i < expect.size(); i++) {
            long long actual = maxTotalValue(nums[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("3691", leetcode::MaximumTotalSubarrayValueII);
