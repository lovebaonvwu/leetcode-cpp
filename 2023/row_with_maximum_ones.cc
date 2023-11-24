class Solution {
 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> ans{0, 0};
    for (int i = 0; i < mat.size(); ++i) {
      int cnt = 0;
      for (int j = 0; j < mat[0].size(); ++j) {
        cnt += mat[i][j] == 1;
      }

      if (cnt > ans[1]) {
        ans[0] = i;
        ans[1] = cnt;
      }
    }

    return ans;
  }
};
// Runtime 151 ms
// Memory 60.3 MB