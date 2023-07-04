class Solution {
 public:
  int numberOfGoodSubarraySplits(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n && nums[i] == 0) {
      ++i;
    }

    if (i == n) {
      return 0;
    }

    int mod = 1e9 + 7;
    int cnt = 0;
    long long ans = 1;
    while (i < n) {
      if (nums[i] == 1) {
        ans = (ans * (cnt + 1)) % mod;
        cnt = 0;
      } else {
        ++cnt;
      }
      ++i;
    }

    return ans;
  }
};
// Runtime 326 ms
// Memory 235.2 MB