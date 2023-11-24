class Solution {
 public:
  int findComplement(int num) {
    int ans = 0;

    for (int i = 0; num > 0; ++i) {
      if (!(num & 1)) {
        ans += 1 << i;
      }
      num >>= 1;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 58.33%

class Solution {
 public:
  int findComplement(int num) {
    int ans = 0;

    for (int i = 0; num > 0; ++i) {
      ans = (num % 2 ? 0 : 1) * pow(2, i) + ans;
      num >>= 1;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 55.22%
// Memory Usage: 8.4 MB, less than 33.33%