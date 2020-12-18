class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    dfs(nums, {}, 0);

    return ans;
  }

  void dfs(vector<int>& nums, vector<int> tmp, int begin) {
    if (begin == nums.size()) {
      return;
    }

    unordered_set<int> st;

    for (int i = begin; i < nums.size(); ++i) {
      if (!tmp.empty() && nums[i] < tmp.back()) {
        continue;
      }

      if (st.count(nums[i])) {
        continue;
      }

      st.insert(nums[i]);

      tmp.push_back(nums[i]);

      if (tmp.size() > 1) {
        ans.push_back(tmp);
      }

      dfs(nums, tmp, i + 1);

      tmp.pop_back();
    }
  }
};
// Runtime: 104 ms, faster than 62.65%
// Memory Usage: 30.2 MB, less than 46.05%