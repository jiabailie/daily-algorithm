//
// Created by ruiguo on 2026/8/26.
//

#include "ShortestAndLexicographicallySmallestBeautifulString.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    /**
     * a > b, return 1
     * a == b, return 0
     * a < b, return -1
     * @param a
     * @param b
     * @return
     */
    int ShortestAndLexicographicallySmallestBeautifulString::compare(std::string &a, std::string &b) {
        if (a.size() > b.size()) { return 1; }
        if (a.size() < b.size()) { return -1; }

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) { continue; }
            if (a[i] > b[i]) { return 1; }
            if (a[i] < b[i]) { return -1; }
        }
        return 0;
    }

    std::string ShortestAndLexicographicallySmallestBeautifulString::shortestBeautifulSubstring(std::string s, int k) {
        int cnt = 0;
        int left = 0;
        std::string ans("");

        for (int right = 0; right < s.size(); ++right) {
            if (s[right] == '0') { continue;}

            cnt++;

            if (cnt < k) { continue; }

            while (cnt > k) {
                cnt -= s[left] == '1' ? 1 : 0;
                left++;
            }
            while (s[left] == '0') {
                left++;
            }

            std::string tmp;
            for (int i = left; i <= right; ++i) {
                tmp.push_back(s[i]);
            }

            if (ans.size() == 0 || ans.size() > tmp.size() || compare(ans, tmp) == 1) {
                ans = tmp;
            }
        }
        return ans;
    }

    void ShortestAndLexicographicallySmallestBeautifulString::test() {
        std::vector<std::string> s {"100011001","1011","000","1100100101011001001"};
        std::vector<int> k {3,2,1,7};
        std::vector<std::string> expect {"11001","11","","1100100101011"};
        for (int i = 0; i < expect.size(); i++) {
            std::string actual = shortestBeautifulSubstring(s[i], k[i]);
            std::cout << (actual == expect[i] ? "PASS" : "FAIL") << std::endl;
        }
    }
}
REGISTER_LEETCODE_SOLUTION("2904", leetcode::ShortestAndLexicographicallySmallestBeautifulString);