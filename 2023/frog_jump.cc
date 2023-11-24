class Solution {
 public:
  bool canCross(vector<int>& stones) {
    if (stones[1] != 1) {
      return false;
    }

    unordered_map<int, int> mp;
    for (int i = 0; i < stones.size(); ++i) {
      mp[stones[i]] = i;
    }
    vector<vector<int>> dp(stones.size(), vector<int>(2001, -1));

    function<bool(int, int)> dfs = [&](int i, int k) -> bool {
      if (i == stones.back()) {
        return dp[mp[i]][k] = 1;
      }

      if (k < 1) {
        return dp[mp[i]][k] = 0;
      }

      if (dp[mp[i]][k] != -1) {
        return dp[mp[i]][k];
      }

      if (mp.find(i + k - 1) != mp.end()) {
        if (dfs(i + k - 1, k - 1)) {
          return dp[mp[i]][k] = 1;
        }
      }

      if (mp.find(i + k) != mp.end()) {
        if (dfs(i + k, k)) {
          return dp[mp[i]][k] = 1;
        }
      }

      if (mp.find(i + k + 1) != mp.end()) {
        if (dfs(i + k + 1, k + 1)) {
          return dp[mp[i]][k] = 1;
        }
      }

      return dp[mp[i]][k] = 0;
    };

    return dfs(1, 1) == 1;
  }
};
// 52ms
// 375.64MB