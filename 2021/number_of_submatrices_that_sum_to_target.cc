class Solution {
 public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        for (int k = 0; k < m; ++k) {
          sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);

          if (mp.find(sum - target) != mp.end()) {
            ans += mp[sum - target];
          }

          ++mp[sum];
        }
      }
    }

    return ans;
  }
};
// Runtime: 592 ms, faster than 77.47%
// Memory Usage: 150.9 MB, less than 64.54%