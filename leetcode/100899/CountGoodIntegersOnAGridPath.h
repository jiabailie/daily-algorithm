//
// Created by Ruiguo Yang on 2026/4/19.
//

#ifndef ALGORITHM_COUNTGOODINTEGERSONAGRIDPATH_H
#define ALGORITHM_COUNTGOODINTEGERSONAGRIDPATH_H

#include <cstring>
#include "../Base.h"

typedef long long ll;

namespace leetcode {
    class CountGoodIntegersOnAGridPath: public Base {
    private:
        ll dp[17][2][11];
        bool isOnPath[16];
        ll solve(int pos, bool isTight, int lastPathDigit, const std::string& s);
        ll countGood(ll n);
    public:
        long long countGoodIntegersOnPath(long long l, long long r, std::string directions);
        void test() override;
    };
}


#endif //ALGORITHM_COUNTGOODINTEGERSONAGRIDPATH_H