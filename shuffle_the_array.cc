class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
      ans.push_back(nums[i]);
      ans.push_back(nums[i + n]);
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 26.68%
// Memory Usage: 9.9 MB, less than 100.00%

class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(2 * n);

    for (int i = 0, j = 0; i < n; ++i) {
      ans[j++] = nums[i];
      ans[j++] = nums[i + n];
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 26.68%
// Memory Usage: 9.9 MB, less than 100.00%