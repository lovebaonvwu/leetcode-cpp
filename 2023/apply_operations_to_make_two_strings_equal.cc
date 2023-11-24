class Solution {
 public:
  int minOperations(string s1, string s2, int x) {
    vector<int> diff;

    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i])
        diff.push_back(i);
    }

    int n = diff.size();
    if (n & 1)
      return -1;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (i >= j)
        return 0;
      if (dp[i][j] != -1)
        return dp[i][j];
      int cost1 = min(diff[i + 1] - diff[i], x) + dfs(i + 2, j);
      int cost2 = min(diff[j] - diff[j - 1], x) + dfs(i, j - 2);
      int cost3 = min(diff[j] - diff[i], x) + dfs(i + 1, j - 1);

      return dp[i][j] = min({cost1, cost2, cost3});
    };

    return dfs(0, n - 1);
  }
};
// 18ms
// 12.25MB