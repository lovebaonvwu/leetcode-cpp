class Solution {
 public:
  int distributeCandies(int n, int limit) {
    int ans = 0;
    for (int i = 0; i <= min(limit, n); ++i) {
      for (int j = 0; j <= min(limit, n - i); ++j) {
        if (n - i - j <= limit) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// 4ms
// 6.32MB