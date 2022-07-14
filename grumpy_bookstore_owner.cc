class Solution {
 public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int ans = 0, n = customers.size();
    for (int i = 0; i < n; ++i) {
      ans += grumpy[i] == 0 ? customers[i] : 0;
    }

    int curmax = 0, gmax = 0;
    for (int r = 0, l = 0; r < n; ++r) {
      curmax += grumpy[r] == 1 ? customers[r] : 0;

      if (r - l + 1 > minutes) {
        curmax -= grumpy[l] == 1 ? customers[l] : 0;
        ++l;
      }

      gmax = max(gmax, curmax);
    }

    return ans + gmax;
  }
};
// Runtime: 48 ms, faster than 63.19%
// Memory Usage: 31.9 MB, less than 86.99%
// 2022.7.14 at 奥盛大厦