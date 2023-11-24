class Solution {
  int dp[501][501] = {};

 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());
    return dfs(satisfaction, 0, 1);
  }

  int dfs(vector<int>& satisfaction, int i, int s) {
    if (i >= satisfaction.size()) {
      return 0;
    }

    if (dp[i][s] > 0) {
      return dp[i][s];
    }

    return dp[i][s] =
               max(dfs(satisfaction, i + 1, s),
                   satisfaction[i] * s + dfs(satisfaction, i + 1, s + 1));
  }
};
// Runtime: 88 ms, faster than 6.00%
// Memory Usage: 7.7 MB, less than 100.00%

class Solution {
 public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end());

    int ans = 0, n = satisfaction.size(), tmp = 0;

    for (int i = n - 1; i >= 0; --i) {
      if (tmp + satisfaction[i] <= 0) {
        break;
      }

      tmp += satisfaction[i];

      ans += tmp;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 100.00%