class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (1LL * m * k > n)
      return -1;

    long long lo = 1;
    long long hi = *max_element(begin(bloomDay), end(bloomDay));

    while (lo < hi) {
      long long md = (lo + hi) / 2;
      int bouquet = 0;
      for (int i = 0, cnt = 0; i < n; ++i) {
        if (bloomDay[i] <= md) {
          ++cnt;
        } else {
          cnt = 0;
        }

        if (cnt == k) {
          ++bouquet;
          cnt = 0;
        }
      }

      if (bouquet < m) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }

    return lo;
  }
};
// 107 ms
// 68.93 MB