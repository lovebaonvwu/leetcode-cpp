class Solution {
 public:
  int countWays(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] < i + 1 && nums[i + 1] > i + 1) {
        ++ans;
      }
    }

    ans += nums.size() > nums.back();
    ans += 0 < nums[0];

    return ans;
  }
};
// 90ms
// 72.06MB