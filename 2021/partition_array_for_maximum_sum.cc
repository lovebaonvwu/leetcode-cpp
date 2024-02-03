class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; ++i) {
      int m = INT_MIN;

      for (int j = 1; j <= min(i, k); ++j) {
        m = max(m, arr[i - j]);

        dp[i] = max(dp[i], dp[i - j] + j * m);
      }
    }

    return dp[n];
  }
};
// Runtime: 27 ms, faster than 22.07%
// Memory Usage: 8.6 MB, less than 54.25%
// 2021.09.01 at 奥盛大厦

class Solution {
 public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> dp(n, -1);

    function<int(int)> dfs = [&](int i) -> int {
      if (i == n)
        return 0;

      if (dp[i] != -1) {
        return dp[i];
      }

      int ret = 0;
      int curmax = 0;
      for (int j = i; j < min(n, i + k); ++j) {
        curmax = max(curmax, arr[j]);
        ret = max(ret, curmax * (j - i + 1) + dfs(j + 1));
      }

      return dp[i] = ret;
    };

    return dfs(0);
  }
};