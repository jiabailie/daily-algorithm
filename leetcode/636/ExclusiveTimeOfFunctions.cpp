//
// Created by Ruiguo Yang on 2026/6/3.
//

#include "ExclusiveTimeOfFunctions.h"

#include <iostream>
#include <stack>

namespace leetcode {
    std::vector<int> ExclusiveTimeOfFunctions::exclusiveTime(int n, std::vector<std::string> &logs) {
        // idx, start timestamp
        std::stack<std::pair<int, int>> st;
        std::vector<int> res(n, 0);
        for (auto& log: logs) {
            char type[10];
            int idx = 0;
            int timestamp = 0;
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);

            if (type[0] == 's') {
                if (!st.empty()) {
                    res[st.top().first] += timestamp - st.top().second;
                    st.top().second = timestamp;
                }
                st.emplace(idx, timestamp);
                continue;
            }

            auto t = st.top();
            st.pop();
            res[t.first] += timestamp - t.second + 1;
            if (!st.empty()) {
                st.top().second = timestamp + 1;
            }
        }
        return res;
    }

    void ExclusiveTimeOfFunctions::test() {
        std::vector<int> n {2,1,2};
        std::vector<std::vector<std::string>> logs {
            {"0:start:0","1:start:2","1:end:5","0:end:6"},
            {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"},
            {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"}
        };
        std::vector<std::vector<int>> expect {
            {3,4},
            {8},
            {7,1}
        };
        for (int i = 0; i < expect.size(); i++) {
            std::vector<int> actual = exclusiveTime(n[i], logs[i]);
            bool isEqual = std::equal(expect[i].begin(), expect[i].end(), actual.begin(), actual.end());
            std::cout << (isEqual ? "PASS" : "FAIL") << std::endl;
        }
    }
}

REGISTER_LEETCODE_SOLUTION("636", leetcode::ExclusiveTimeOfFunctions);
