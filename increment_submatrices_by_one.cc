class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> ans(n, vector<int>(n));

    for (auto& q : queries) {
      int x0 = q[0];
      int y0 = q[1];
      int x1 = q[2];
      int y1 = q[3];

      for (int i = x0; i <= x1; ++i) {
        for (int j = y0; j <= y1; ++j) {
          ++ans[i][j];
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> ans(n, vector<int>(n));

    for (auto& q : queries) {
      int x0 = q[0];
      int y0 = q[1];
      int x1 = q[2];
      int y1 = q[3];

      ans[x0][y0] += 1;
      if (y1 + 1 < n) {
        ans[x0][y1 + 1] -= 1;
      }
      if (x1 + 1 < n) {
        ans[x1 + 1][y0] -= 1;
      }
      if (x1 + 1 < n && y1 + 1 < n) {
        ans[x1 + 1][y1 + 1] += 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < n; ++j) {
        ans[i][j] += ans[i][j - 1];
      }
    }

    for (int j = 0; j < n; ++j) {
      for (int i = 1; i < n; ++i) {
        ans[i][j] += ans[i - 1][j];
      }
    }

    return ans;
  }
};
// Runtime 247 ms
// Memory 82 MB
// 2023.2.17 at 奥盛大厦