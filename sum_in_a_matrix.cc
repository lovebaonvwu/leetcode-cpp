class Solution {
 public:
  int matrixSum(vector<vector<int>>& nums) {
    for (auto& row : nums) {
      sort(row.begin(), row.end());
    }

    int ans = 0;
    for (int j = 0; j < nums[0].size(); ++j) {
      int score = 0;
      for (int i = 0; i < nums.size(); ++i) {
        score = max(score, nums[i][j]);
      }

      ans += score;
    }

    return ans;
  }
};
// Runtime 135 ms
// Memory 48 MB