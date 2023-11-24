class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int ans = INT_MAX;

    int n = blocks.size();
    for (int i = 0, w = 0; i < n; ++i) {
      w += blocks[i] == 'W';
      if (i >= k) {
        w -= blocks[i - k] == 'W';
      }
      if (i >= k - 1) {
        ans = min(ans, w);
      }
    }

    return ans;
  }
};
// Runtime: 5 ms, faster than 77.78%
// Memory Usage: 6.1 MB, less than 100.00%
// 2022.8.27 at 奥盛大厦