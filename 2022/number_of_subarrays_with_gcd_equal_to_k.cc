class Solution {
 public:
  int subarrayGCD(vector<int>& nums, int k) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int x = nums[i];
      for (int j = i; j < nums.size(); ++j) {
        x = gcd(x, nums[j]);
        ans += x == k;
      }
    }

    return ans;
  }
};
// Runtime: 65 ms, faster than 35.36%
// Memory Usage: 9 MB, less than 6.82%
// 2022.10.26 at 奥盛大厦