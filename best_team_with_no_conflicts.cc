class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();

    vector<pair<int, int>> stats;
    for (int i = 0; i < n; ++i) {
      stats.push_back({ages[i], scores[i]});
    }

    sort(stats.begin(), stats.end());

    vector<vector<int>> memo(n, vector<int>(n, -1));

    return dfs(stats, memo, -1, 0);
  }

  int dfs(vector<pair<int, int>>& stats,
          vector<vector<int>>& memo,
          int prev,
          int cur) {
    if (cur >= stats.size()) {
      return 0;
    }

    if (memo[prev + 1][cur] != -1) {
      return memo[prev + 1][cur];
    }

    if (prev == -1 || stats[cur].second >= stats[prev].second) {
      return memo[prev + 1][cur] =
                 max(stats[cur].second + dfs(stats, memo, cur, cur + 1),
                     dfs(stats, memo, prev, cur + 1));
    }

    return memo[prev + 1][cur] = dfs(stats, memo, prev, cur + 1);
  }
};
// Runtime 503 ms
// Memory 133.5 MB
// 2023.1.31 at 奥盛大厦

class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();

    vector<pair<int, int>> stats;
    for (int i = 0; i < n; ++i) {
      stats.push_back({ages[i], scores[i]});
    }

    sort(stats.begin(), stats.end());

    return findMaxScore(stats);
  }

  int findMaxScore(vector<pair<int, int>>& stats) {
    int n = stats.size();
    int ans = 0;

    vector<int> dp(n);

    for (int i = 0; i < n; ++i) {
      dp[i] = stats[i].second;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] = max(dp[i], stats[i].second >= stats[j].second
                               ? dp[j] + stats[i].second
                               : stats[i].second);
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Runtime 251 ms
// Memory 20 MB
// 2023.1.31 at 奥盛大厦