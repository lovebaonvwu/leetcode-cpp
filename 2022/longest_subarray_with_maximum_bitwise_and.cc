class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int ans = 0;
    int target = *max_element(nums.begin(), nums.end());
    int cnt = 0;
    for (auto n : nums) {
      if (n == target) {
        ++cnt;
      } else {
        ans = max(ans, cnt);
        cnt = 0;
      }
    }

    ans = max(ans, cnt);

    return ans;
  }
};
// Runtime: 188 ms, faster than 82.75%
// Memory Usage: 82.3 MB, less than 14.22%
// 2022.9.29 at 奥盛大厦