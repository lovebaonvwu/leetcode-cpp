class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& A) {
    vector<vector<int>> ans(A[0].size(), vector<int>(A.size()));

    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < A[0].size(); ++j) {
        ans[j][i] = A[i][j];
      }
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 97.89%
// Memory Usage: 11.4 MB, less than 100.00%