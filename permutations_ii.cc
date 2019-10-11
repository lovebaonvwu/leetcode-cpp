class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    dfs(nums, 0);

    return ans;
  }

  void dfs(vector<int> nums, int pos) {
    if (pos == nums.size()) {
      ans.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      if (i != pos && nums[i] == nums[pos]) {
        continue;
      }

      swap(nums[i], nums[pos]);

      dfs(nums, pos + 1);
    }
  }
};
// Runtime: 24 ms, faster than 68.55%
// Memory Usage: 11 MB, less than 26.19%