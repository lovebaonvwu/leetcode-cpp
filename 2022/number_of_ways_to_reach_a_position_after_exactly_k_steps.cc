class Solution {
  int mod = 1e9 + 7;
  int memo[3001][3001];

 public:
  int numberOfWays(int startPos, int endPos, int k) {
    memset(memo, -1, sizeof(memo));
    return dfs(startPos + 1000, endPos + 1000, k);
  }

  long long dfs(int cur, int end, int k) {
    if (k == 0) {
      if (cur == end) {
        return 1;
      } else {
        return 0;
      }
    }

    if (memo[cur][k] != -1) {
      return memo[cur][k];
    }

    memo[cur][k] = (dfs(cur + 1, end, k - 1) + dfs(cur - 1, end, k - 1)) % mod;

    return memo[cur][k];
  }
};
// Runtime: 464 ms, faster than 38.62%
// Memory Usage: 45.5 MB, less than 58.15%
// 2022.9.7 at 奥盛大厦