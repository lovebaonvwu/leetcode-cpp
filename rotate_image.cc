class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i; j < matrix[i].size(); ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    int col = matrix.size() / 2;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < col; ++j) {
        swap(matrix[i][j], matrix[i][matrix.size() - 1 - j]);
      }
    }
  }
};  // 4ms

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i; j < matrix[i].size(); ++j) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
      }
    }

    int col = matrix.size() / 2;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < col; ++j) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i][matrix.size() - 1 - j];
        matrix[i][matrix.size() - 1 - j] = temp;
      }
    }
  }
};  // 8ms