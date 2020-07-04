class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> ans(n);

    ans[0] = 1;

    for (int i = 0, j = 0, k = 0, cur = 1; cur < n; ++cur) {
      ans[cur] = min(ans[i] * 2, min(ans[j] * 3, ans[k] * 5));

      if (ans[cur] == ans[i] * 2) {
        ++i;
      }

      if (ans[cur] == ans[j] * 3) {
        ++j;
      }

      if (ans[cur] == ans[k] * 5) {
        ++k;
      }
    }

    return ans[n - 1];
  }
};
// Runtime: 20 ms, faster than 45.76%
// Memory Usage: 7.7 MB, less than 69.09%