class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size();
    int n = B.size();

    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      dp[i][0] = A[i] == B[0] ? 1 : 0;
    }

    for (int j = 0; j < n; ++j) {
      dp[0][j] = B[j] == A[0] ? 1 : 0;
    }

    int ans = 0;

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (A[i] == B[j]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }

        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
};
// Runtime: 456 ms, faster than 11.06%
// Memory Usage: 108.9 MB, less than 41.69%
// 2021.7.8 at 奥盛大厦