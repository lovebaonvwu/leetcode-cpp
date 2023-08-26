class Solution {
 public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(),
         [](auto& a, auto& b) { return a[0] < b[0]; });

    int n = pairs.size();
    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (pairs[i][0] > pairs[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        } else {
          dp[i] = max(dp[i], dp[j]);
        }
      }
    }

    return dp[n - 1];
  }
};
// 248ms
// 22.88MB