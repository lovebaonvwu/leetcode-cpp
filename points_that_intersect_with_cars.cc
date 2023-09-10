class Solution {
 public:
  int numberOfPoints(vector<vector<int>>& nums) {
    sort(nums.begin(), nums.end(),
         [](auto& a, auto& b) { return a[0] < b[0]; });

    auto prev = nums[0];
    int ans = prev[1] - prev[0] + 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i][0] > prev[1]) {
        ans += nums[i][1] - nums[i][0] + 1;
        prev = nums[i];
      } else if (nums[i][1] > prev[1]) {
        ans += nums[i][1] - prev[1];
        prev[1] = nums[i][1];
      }
    }

    return ans;
  }
};
// 12ms
// 24.52MB
