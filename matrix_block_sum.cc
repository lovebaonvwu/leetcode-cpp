class Solution {
 public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
    size_t m = mat.size();
    size_t n = mat[0].size();

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int sum = 0;

        for (int p = i - K; p <= i + K; ++p) {
          for (int q = j - K; q <= j + K; ++q) {
            if (p >= 0 && p < m && q >= 0 && q < n) {
              sum += mat[p][q];
            }
          }
        }

        ans[i][j] = sum;
      }
    }

    return ans;
  }
};
// Runtime: 608 ms, faster than 19.78%
// Memory Usage: 11.1 MB, less than 100.00%