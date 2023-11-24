class Solution {
 public:
  int maxProductDifference(vector<int>& nums) {
    int w = 0, x = 0, y = 10000, z = 10000;

    for (auto n : nums) {
      if (n > x) {
        w = x;
        x = n;
      } else if (n > w) {
        w = n;
      }

      if (n < y) {
        z = y;
        y = n;
      } else if (n < z) {
        z = n;
      }
    }

    return x * w - y * z;
  }
};
// Runtime: 28 ms, faster than 77.59%
// Memory Usage: 20.4 MB, less than 61.69%
// 2021.7.9 at 奥盛大厦