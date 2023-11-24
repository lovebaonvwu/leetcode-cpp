class NumMatrix {
  vector<vector<int>>& mat;

 public:
  NumMatrix(vector<vector<int>>& matrix) : mat(matrix) {}

  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;

    for (int i = row1; i <= row2; ++i) {
      for (int j = col1; j <= col2; ++j) {
        sum += mat[i][j];
      }
    }

    return sum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// Time Limit Exceeded

class NumMatrix {
  vector<vector<int>> mat;

 public:
  NumMatrix(vector<vector<int>>& matrix) : mat(matrix) {
    int m = matrix.size() + 1;
    int n = matrix[0].size() + 1;

    mat = vector<vector<int>>(m, vector<int>(n));

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] +
                    matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return mat[row2 + 1][col2 + 1] - mat[row2 + 1][col1] - mat[row1][col2 + 1] +
           mat[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// Runtime: 16 ms, faster than 88.69%
// Memory Usage: 15.5 MB, less than 24.24%