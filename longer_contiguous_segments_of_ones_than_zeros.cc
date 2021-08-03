class Solution {
 public:
  bool checkZeroOnes(string s) {
    int max_ones = s[0] == '1' ? 1 : 0;
    int max_zeros = !max_ones;
    int ones = max_ones;
    int zeros = max_zeros;

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        max_ones = max(max_ones, ones);
        max_zeros = max(max_zeros, zeros);

        ones = s[i] == '1' ? 1 : 0;
        zeros = !ones;
      } else {
        ones += s[i] == '1';
        zeros += s[i] == '0';
      }
    }

    max_ones = max(max_ones, ones);
    max_zeros = max(max_zeros, zeros);

    return max_ones > max_zeros;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 45.91%
// 2021.8.3 at 奥盛大厦