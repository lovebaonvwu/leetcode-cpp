class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    function<int(int, int)> dfs = [&](int i, int k) {
      if (k < 0) {
        return INT_MAX / 2;
      }

      if (i + k >= n) {
        return 0;
      }

      int ans = dp[i][k];
      if (ans != -1) {
        return ans;
      }

      ans = dfs(i + 1, k - 1);

      int same = 0;
      int diff = 0;
      int len = 0;

      for (int j = i; j < n && diff <= k; ++j) {
        if (s[i] == s[j]) {
          ++same;
          if (same <= 2 || same == 10 || same == 100) {
            ++len;
          }
        } else {
          ++diff;
        }

        ans = min(ans, len + dfs(j + 1, k - diff));
      }

      return dp[i][k] = ans;
    };

    return dfs(0, k);
  }
};
// Runtime: 79 ms, faster than 66.67%
// Memory Usage: 8.1 MB, less than 58.33%
// 2022.10.15 at 奥盛大厦