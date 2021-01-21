class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> ans;

    for (int i = 0, n = nums.size(); i < n; ++i) {
      while (!ans.empty() && nums[i] < ans.back() && ans.size() + n - i > k) {
        ans.pop_back();
      }

      if (ans.size() < k) {
        ans.push_back(nums[i]);
      }
    }

    return ans;
  }
};
// Runtime: 184 ms, faster than 98.74%
// Memory Usage: 109.4 MB, less than 45.70%