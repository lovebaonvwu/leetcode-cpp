class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int bit = 0, ans = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      while ((bit & nums[i]) > 0) {
        bit ^= nums[j++];
      }
      bit |= nums[i];
      ans = max(ans, i - j + 1);
    }

    return ans;
  }
};
// Runtime: 276 ms, faster than 57.10%
// Memory Usage: 57.2 MB, less than 19.23%
// 2022.9.6 at 奥盛大厦