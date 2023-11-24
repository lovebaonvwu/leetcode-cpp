class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    dfs(nums, 0);

    return ans;
  }

  void dfs(vector<int> nums, int pos) {
    if (pos == nums.size()) {
      ans.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      swap(nums[i], nums[pos]);

      dfs(nums, pos + 1);
    }
  }
};
// Runtime: 8 ms, faster than 98.48%
// Memory Usage: 9.8 MB, less than 26.87%

class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    dfs(nums, 0);

    return ans;
  }

  void dfs(vector<int>& nums, int pos) {
    if (pos == nums.size()) {
      ans.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      swap(nums[i], nums[pos]);

      dfs(nums, pos + 1);

      swap(nums[pos], nums[i]);
    }
  }
};
// Runtime: 12 ms, faster than 66.90%
// Memory Usage: 9.5 MB, less than 46.27%