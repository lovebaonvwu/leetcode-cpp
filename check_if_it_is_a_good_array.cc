class Solution {
  int gcd(int a, int b) {
    if (b == 0) {
      return a;
    }

    return gcd(b, a % b);
  }

 public:
  bool isGoodArray(vector<int>& nums) {
    int x = nums[0];

    for (auto n : nums) {
      x = gcd(x, n);
    }

    return x == 1;
  }
};
// Runtime: 112 ms, faster than 7.41%
// Memory Usage: 29.7 MB, less than 6.48%