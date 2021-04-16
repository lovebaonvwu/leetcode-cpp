class Solution {
  int rev(int x) {
    int ret = 0;

    while (x > 0) {
      ret = ret * 10 + (x % 10);

      x /= 10;
    }

    return ret;
  }

 public:
  int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> mp;

    int ans = 0, mod = 1e9 + 7;
    for (auto n : nums) {
      int target = n - rev(n);
      ans = (ans + mp[target]) % mod;

      ++mp[target];
    }

    return ans;
  }
};
// Runtime: 124 ms, faster than 49.70%
// Memory Usage: 56.9 MB, less than 16.78%