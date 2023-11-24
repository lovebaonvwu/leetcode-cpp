class Solution {
 public:
  long long distributeCandies(int n, int limit) {
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    function<long long(int, int)> dfs = [&](int n, int k) -> long long {
      if (n == 0) {
        return 1;
      }

      if (k == 0 || n < 0) {
        return 0;
      }

      if (dp[n][k] != -1) {
        return dp[n][k];
      }

      long long res = 0;
      for (int i = 0; i <= limit; ++i) {
        res += dfs(n - i, k - 1);
      }

      return dp[n][k] = res;
    };

    return dfs(n, 3);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long distributeCandies(int n, int limit) {
    int a_max = min(n, limit);
    int a_min = max(0, n - 2 * limit);

    long long ans = 0;
    for (int i = a_min; i <= a_max; ++i) {
      int b_max = min(n - i, limit);
      int b_min = max(0, n - i - limit);
      ans += b_max - b_min + 1;
    }

    return ans;
  }
};
// 30ms
// 6.29MB