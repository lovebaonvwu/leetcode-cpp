class Solution {
 public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int ans = 0;
    for (int i = 0, j = 0; i < players.size() && j < trainers.size(); ++j) {
      if (players[i] <= trainers[j]) {
        ++ans;
        ++i;
      }
    }

    return ans;
  }
};
// Runtime: 519 ms, faster than 8.95%
// Memory Usage: 76.6 MB, less than 48.33%
// 2022.9.28 at 奥盛大厦