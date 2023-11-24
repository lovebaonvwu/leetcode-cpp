class Twitter {
  int cnt;
  const int q_size = 10;

  unordered_map<int, vector<pair<int, int>>> tweets;
  unordered_map<int, unordered_set<int>> followees;

 public:
  /** Initialize your data structure here. */
  Twitter() { cnt = 0; }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    follow(userId, userId);

    tweets[userId].push_back({cnt++, tweetId});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> pq;

    for (const auto& f : followees[userId]) {
      for (const auto& t : tweets[f]) {
        pq.push(t);
      }
    }

    vector<int> ans;
    for (int i = 0; i < q_size && !pq.empty(); ++i) {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    followees[followerId].insert(followeeId);
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      followees[followerId].erase(followeeId);
    }
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// Runtime: 44 ms, faster than 84.43%
// Memory Usage: 22.3 MB, less than 33.33%

class Twitter {
  int cnt;
  const int q_size = 10;

  unordered_map<int, map<int, int>> tweets;
  unordered_map<int, unordered_map<int, bool>> followees;

 public:
  /** Initialize your data structure here. */
  Twitter() { cnt = 0; }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    follow(userId, userId);

    if (tweets[userId].size() == q_size) {
      tweets[userId].erase(tweets[userId].begin());
    }

    tweets[userId][cnt++] = tweetId;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> ans;

    for (int i = cnt; i >= 0; --i) {
      if (ans.size() == q_size) {
        break;
      }

      for (const auto& f : followees[userId]) {
        if (f.second) {
          if (tweets[f.first].find(i) != tweets[f.first].end()) {
            ans.push_back(tweets[f.first][i]);
          }
        }
      }
    }

    return ans;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    followees[followerId][followeeId] = true;
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      followees[followerId][followeeId] = false;
    }
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// Runtime: 324 ms, faster than 5.40%
// Memory Usage: 21.8 MB, less than 33.33%