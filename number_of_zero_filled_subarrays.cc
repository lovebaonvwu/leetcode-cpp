class Solution {
 public:
  long long zeroFilledSubarray(vector<int>& nums) {
    long long ans = 0;

    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        ++cnt;

        ans += cnt;
      } else {
        cnt = 0;
      }
    }

    return ans;
  }
};
// Runtime: 282 ms, faster than 100.00%
// Memory Usage: 107.5 MB, less than 50.00%
// 2022.7.26 at 奥盛大厦