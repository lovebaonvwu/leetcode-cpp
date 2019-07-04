class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (!nums.size()) {
      return 0;
    }

    int ans = nums[0];
    int tmp = ans;

    for (int i = 1; i < nums.size(); ++i) {
      if (tmp < 0) {
        tmp = nums[i];
      } else {
        tmp += nums[i];
      }

      ans = max(ans, tmp);
    }

    return ans;
  }
};  // 4ms