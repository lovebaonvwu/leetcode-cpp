class Leaderboard {
  int board[10001];

 public:
  Leaderboard() { memset(board, 0, sizeof(board)); }

  void addScore(int playerId, int score) { board[playerId] += score; }

  int top(int K) {
    vector<int> tmp(begin(board), end(board));
    sort(tmp.rbegin(), tmp.rend());

    int ret = 0;
    int i = 0;
    while (K-- > 0) {
      ret += tmp[i++];
    }

    return ret;
  }

  void reset(int playerId) { board[playerId] = 0; }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
// Runtime 938 ms
// Memory 46 MB
// 2023.2.1 at 奥盛大厦

class Leaderboard {
  int board[10001];
  map<int, int> mp;

 public:
  Leaderboard() { memset(board, 0, sizeof(board)); }

  void addScore(int playerId, int score) {
    int oldScore = board[playerId];
    if (oldScore > 0) {
      --mp[oldScore];
      if (mp[oldScore] == 0) {
        mp.erase(oldScore);
      }
    }
    int newScore = oldScore + score;

    board[playerId] = newScore;
    ++mp[newScore];
  }

  int top(int K) {
    int ret = 0;

    for (auto it = prev(mp.end()); K > 0; --it) {
      ret += min(K, it->second) * it->first;
      K -= min(K, it->second);
    }
    return ret;
  }

  void reset(int playerId) {
    int oldScore = board[playerId];
    if (oldScore > 0) {
      --mp[oldScore];
      if (mp[oldScore] == 0) {
        mp.erase(oldScore);
      }
    }

    board[playerId] = 0;
  }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
// Runtime 18 ms
// Memory 11.4 MB
// 2023.2.1 at 奥盛大厦