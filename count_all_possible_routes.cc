class Solution {
  vector<vector<int>> dp;
  int n;
  int mod;
  int target;

 public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    n = locations.size();
    mod = 1e9 + 7;
    target = finish;
    dp.resize(n, vector<int>(fuel + 1, -1));

    return dfs(locations, start, fuel);
  }

  int dfs(const vector<int>& locations, int start, int fuel) {
    if (dp[start][fuel] > -1) {
      return dp[start][fuel];
    }

    int cnt = 0;
    if (start == target) {
      if (fuel == 0) {
        return 1;
      } else if (fuel > 0) {
        cnt += 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i == start) {
        continue;
      }

      int consume = abs(locations[i] - locations[start]);
      if (consume > fuel) {
        continue;
      }

      cnt = (cnt + dfs(locations, i, fuel - consume)) % mod;
    }

    return dp[start][fuel] = cnt;
  }
};
// Runtime 200 ms
// Memory 11.8 MB