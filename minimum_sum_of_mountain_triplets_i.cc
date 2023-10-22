class Solution {
 public:
  int minimumSum(vector<int>& nums) {
    int ans = INT_MAX;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (nums[i] < nums[j] && nums[j] > nums[k]) {
            ans = min(ans, nums[i] + nums[j] + nums[k]);
          }
        }
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// 11ms
// 21.20MB