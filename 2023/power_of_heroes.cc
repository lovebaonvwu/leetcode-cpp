class Solution {
 public:
  int sumOfPower(vector<int>& nums) {
    long long ans = 0;
    int mod = 1e9 + 7;
    long long sum = 0;

    sort(nums.begin(), nums.end());
    for (auto n : nums) {
      ans = (ans + (sum + n) * n % mod * n % mod) % mod;
      sum = (sum * 2 + n) % mod;
    }

    return ans;
  }
};
// 89ms
// 93.23MB