class Solution {
 public:
  int findGCD(vector<int>& nums) {
    int a = INT_MAX, b = INT_MIN;

    for (auto n : nums) {
      a = min(a, n);
      b = max(b, n);
    }

    return gcd(a, b);
  }

  int gcd(int a, int b) {
    if (b) {
      return gcd(b, a % b);
    } else {
      return a;
    }
  }
};
// Runtime: 4 ms, faster than 57.14%
// Memory Usage: 12.5 MB, less than 23.81%
// 2021.8.23 at 奥盛大厦