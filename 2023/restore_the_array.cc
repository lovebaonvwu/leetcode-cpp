class Solution {
  int memo[100001];

 public:
  int numberOfArrays(string s, int k) { return dfs(s, 0, k); }

  int dfs(const string& s, int i, int k) {
    if (i == s.size()) {
      return 1;
    }

    if (s[i] == '0') {
      return 0;
    }

    if (memo[i]) {
      return memo[i];
    }

    int mod = 1e9 + 7;
    for (long long sz = 1, sum = 0; i + sz <= s.size(); ++sz) {
      sum = sum * 10 + (s[i + sz - 1] - '0');
      if (sum > k) {
        break;
      }

      memo[i] = (memo[i] + dfs(s, i + sz, k)) % mod;
    }

    return memo[i];
  }
};
// Runtime 66 ms
// Memory 19.8 MB

class Solution {
 public:
  int numberOfArrays(string s, int k) {
    int n = s.size();
    vector<int> dp(n + 1);
    dp[n] = 1;

    int mod = 1e9 + 7;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '0') {
        continue;
      }

      for (long long sz = 1, sum = 0; i + sz <= n; ++sz) {
        sum = sum * 10 + (s[i + sz - 1] - '0');
        if (sum > k) {
          break;
        }

        dp[i] = (dp[i] + dp[i + sz]) % mod;
      }
    }

    return dp[0];
  }
};
// Runtime 57 ms
// Memory 11.9 MB