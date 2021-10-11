class Solution {
 public:
  int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> arr(m * n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        arr[i * n + j] = grid[i][j];
      }
    }

    sort(arr.begin(), arr.end());

    int md = arr[arr.size() / 2];

    int ans = 0;

    for (int i = 0; i < arr.size(); ++i) {
      if (abs(arr[i] - md) % x != 0) {
        return -1;
      }

      ans += abs(arr[i] - md) / x;
    }

    return ans;
  }
};
// Runtime: 447 ms, faster than 12.50%
// Memory Usage: 78.2 MB, less than 6.25%
// 2021.10.11 at 奥盛大厦