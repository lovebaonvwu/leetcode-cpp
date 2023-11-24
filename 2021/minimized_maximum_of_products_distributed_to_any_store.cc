class Solution {
  int storeWeNeed(const vector<int>& q, int capacity) {
    int cnt = 0;

    for (auto n : q) {
      cnt += (n + capacity - 1) / capacity;
    }

    return cnt;
  }

 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int lo = 1, hi = 100000;

    while (lo < hi) {
      int md = lo + (hi - lo) / 2;

      int stores = storeWeNeed(quantities, md);

      if (stores > n) {
        lo = md + 1;
      } else if (stores <= n) {
        hi = md;
      }
    }

    return lo;
  }
};
// Runtime: 172 ms, faster than 83.94%
// Memory Usage: 84.5 MB, less than 43.78%
// 2021.11.11 at 奥盛大厦