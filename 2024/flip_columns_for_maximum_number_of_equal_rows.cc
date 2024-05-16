class Solution {
 public:
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int ans = 0;
    for (int i = 0; i < m; ++i) {
      vector<int> pattern(n);
      for (int j = 0; j < n; ++j)
        pattern[j] = 1 - matrix[i][j];
      int cnt = 0;
      for (int k = i; k < m; ++k) {
        if (matrix[k] == matrix[i] || matrix[k] == pattern)
          ++cnt;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// 204 ms
// 73.83 MB