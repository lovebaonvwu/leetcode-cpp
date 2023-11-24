class Solution {
 public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    int m = rowSum.size();
    int n = colSum.size();

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = min(rowSum[i], colSum[j]);

        rowSum[i] -= ans[i][j];
        colSum[j] -= ans[i][j];
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 49.58%
// Memory Usage: 33.7 MB, less than 5.50%