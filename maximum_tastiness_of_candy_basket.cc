class Solution {
 public:
  int maximumTastiness(vector<int>& price, int k) {
    sort(price.begin(), price.end());

    int lo = 0, hi = price.back() - price.front();
    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      int cnt = 1;
      for (int i = 1, j = 0; i < price.size(); ++i) {
        if (price[i] - price[j] >= md) {
          ++cnt;
          j = i;
        }
      }

      if (cnt >= k) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }

    return lo;
  }
};
// Runtime 505 ms
// Memory 48.5 MB
// 2022.1.4 at 奥盛大厦