class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> row = triangle[triangle.size() - 1];

    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        row[j] = triangle[i][j] + min(row[j], row[j + 1]);
      }
    }

    return row[0];
  }
};  // 8ms

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (!triangle.size()) {
      return 0;
    }

    int ans = INT_MAX;
    int sum = 0;

    dfs(triangle, 0, 0, 0, ans);

    return ans;
  }

  void dfs(vector<vector<int>>& triangle, int row, int col, int sum, int& ans) {
    if (row == triangle.size() - 1) {
      ans = triangle[row][col] + sum < ans ? triangle[row][col] + sum : ans;
      if (col + 1 < triangle[row].size()) {
        ans = triangle[row][col + 1] + sum < ans ? triangle[row][col + 1] + sum
                                                 : ans;
      }

      return;
    }

    dfs(triangle, row + 1, col, sum + triangle[row][col], ans);
    if (col + 1 < triangle[row].size()) {
      dfs(triangle, row + 1, col + 1, sum + triangle[row][col + 1], ans);
    }
  }
};  // Time Limit Exceeded