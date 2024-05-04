class Solution {
 public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> colmax(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        colmax[j] = max(colmax[j], matrix[i][j]);
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = colmax[j];
        }
      }
    }

    return matrix;
  }
};
// 20 ms
// 22.43 MB