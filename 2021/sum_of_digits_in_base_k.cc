class Solution {
 public:
  int sumBase(int n, int k) {
    int ans = 0;

    while (n > 0) {
      ans += n % k;

      n = n / k;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 70.29%
// 2021.10.02 at 茗筑美嘉