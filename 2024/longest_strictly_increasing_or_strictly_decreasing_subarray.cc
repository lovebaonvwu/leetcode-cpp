class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int pitch = 0;
    int ans = 1;
    int n = nums.size();
    for (int i = 1, cnt = 1; i < n; ++i) {
      if (nums[i] == nums[i - 1]) {
        cnt = 1;
        pitch = 0;
      } else if (nums[i] > nums[i - 1] && pitch >= 0) {
        ++cnt;
        pitch = 1;
      } else if (nums[i] < nums[i - 1] && pitch <= 0) {
        ++cnt;
        pitch = -1;
      } else if (nums[i] > nums[i - 1] && pitch < 0) {
        cnt = 2;
        pitch = 1;
      } else if (nums[i] < nums[i - 1] && pitch > 0) {
        cnt = 2;
        pitch = -1;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};