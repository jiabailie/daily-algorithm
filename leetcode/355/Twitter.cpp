//
// Created by Ruiguo on 18/7/2026.
//

#include "Twitter.h"

#include <iostream>
#include <ostream>

namespace leetcode {
    Twitter::Twitter() {
        tweets.clear();
        followed.clear();
    }

    void Twitter::postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    void Twitter::follow(int followerId, int followeeId) {
        if (followed.find(followerId) == followed.end()) {
            followed[followerId] = std::set<int>();
        }
        followed[followerId].insert(followeeId);
    }

    void Twitter::unfollow(int followerId, int followeeId) {
        if (followed.find(followerId) == followed.end()) {
            return;
        }
        followed[followerId].erase(followeeId);
    }

    std::vector<int> Twitter::getNewsFeed(int userId) {
        std::vector<int> ans;
        std::set<int> followedList = followed[userId];
        for (auto t = tweets.rbegin(); t != tweets.rend(); ++t) {
            if (t->first == userId || followedList.find(t->first) != followedList.end()) {
                ans.push_back(t->second);
            }
            if (ans.size() == 10) {
                break;
            }
        }
        return ans;
    }

    void Twitter::test() {
        Twitter* twitter = new Twitter();
        twitter->postTweet(1, 5);

        std::vector<int> actual1 = twitter->getNewsFeed(1);
        std::vector<int> expect1 = {5};
        std::cout << (std::equal(actual1.begin(), actual1.end(), expect1.begin(), expect1.end()) ? "PASS" : "FAIL") << std::endl;

        twitter->follow(1,2);
        twitter->postTweet(2, 6);

        std::vector<int> actual2 = twitter->getNewsFeed(1);
        std::vector<int> expect2 = {6,5};
        std::cout << (std::equal(actual2.begin(), actual2.end(), expect2.begin(), expect2.end()) ? "PASS" : "FAIL") << std::endl;

        twitter->unfollow(1,2);
        std::vector<int> actual3 = twitter->getNewsFeed(1);
        std::vector<int> expect3 = {5};
        std::cout << (std::equal(actual3.begin(), actual3.end(), expect3.begin(), expect3.end()) ? "PASS" : "FAIL") << std::endl;
    }
}

REGISTER_LEETCODE_SOLUTION("355", leetcode::Twitter);