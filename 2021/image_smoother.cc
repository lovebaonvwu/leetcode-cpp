class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (M.size() == 0)
      return M;

    vector<vector<int>> ans(M.size(), vector<int>(M[0].size()));

    for (int i = 0; i < M.size(); ++i) {
      for (int j = 0; j < M[i].size(); ++j) {
        int sum = M[i][j];
        int count = 1;

        if (i - 1 >= 0) {
          sum += M[i - 1][j];
          ++count;

          if (j - 1 >= 0) {
            sum += M[i - 1][j - 1];
            ++count;
          }

          if (j + 1 < M[i].size()) {
            sum += M[i - 1][j + 1];
            ++count;
          }
        }

        if (i + 1 < M.size()) {
          sum += M[i + 1][j];
          ++count;

          if (j - 1 >= 0) {
            sum += M[i + 1][j - 1];
            ++count;
          }

          if (j + 1 < M[i].size()) {
            sum += M[i + 1][j + 1];
            ++count;
          }
        }

        if (j - 1 >= 0) {
          sum += M[i][j - 1];
          ++count;
        }

        if (j + 1 < M[i].size()) {
          sum += M[i][j + 1];
          ++count;
        }

        ans[i][j] = sum / count;
      }
    }

    return ans;
  }
};  // 148ms

class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (M.size() == 0)
      return M;

    vector<vector<int>> ans(M.size(), vector<int>(M[0].size()));

    for (int i = 0; i < M.size(); ++i) {
      for (int j = 0; j < M[i].size(); ++j) {
        int sum = M[i][j];
        int count = 1;

        if (i - 1 >= 0 && j - 1 >= 0) {
          sum += M[i - 1][j - 1];
          ++count;
        }

        if (i - 1 >= 0) {
          sum += M[i - 1][j];
          ++count;
        }

        if (i - 1 >= 0 && j + 1 < M[i].size()) {
          sum += M[i - 1][j + 1];
          ++count;
        }

        if (j - 1 >= 0) {
          sum += M[i][j - 1];
          ++count;
        }

        if (i + 1 < M.size() && j - 1 >= 0) {
          sum += M[i + 1][j - 1];
          ++count;
        }

        if (j + 1 < M[i].size()) {
          sum += M[i][j + 1];
          ++count;
        }

        if (i + 1 < M.size()) {
          sum += M[i + 1][j];
          ++count;
        }

        if (i + 1 < M.size() && j + 1 < M[i].size()) {
          sum += M[i + 1][j + 1];
          ++count;
        }

        ans[i][j] = sum / count;
      }
    }

    return ans;
  }
};  // 156ms