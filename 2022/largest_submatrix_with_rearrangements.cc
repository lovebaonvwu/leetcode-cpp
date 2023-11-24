class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int ans = 0;

    int m = matrix.size(), n = matrix[0].size();

    vector<int> row_height(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          row_height[j] = 0;
        } else {
          row_height[j] += 1;
        }
      }

      vector<int> tmp = row_height;
      sort(tmp.begin(), tmp.end());
      for (int j = 0; j < n; ++j) {
        ans = max(ans, tmp[j] * (n - j));
      }
    }

    return ans;
  }
};
// Runtime: 300 ms, faster than 58.03%
// Memory Usage: 75 MB, less than 58.33%
// 2022.7.15 at 奥盛大厦