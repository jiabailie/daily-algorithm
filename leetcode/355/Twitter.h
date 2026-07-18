//
// Created by Ruiguo on 18/7/2026.
//

#ifndef ALGORITHM_DESIGNTWITTER_H
#define ALGORITHM_DESIGNTWITTER_H

#include "../Base.h"
#include <set>
#include <vector>
#include <unordered_map>

namespace leetcode {
    class Twitter: public Base {
    private:
        std::vector<std::pair<int, int>> tweets;
        std::unordered_map<int, std::set<int>> followed;
    public:
        Twitter();
        void postTweet(int userId, int tweetId);
        std::vector<int> getNewsFeed(int userId);
        void follow(int followerId, int followeeId);
        void unfollow(int followerId, int followeeId);
        void test() override;
    };
}



#endif //ALGORITHM_DESIGNTWITTER_H
