class Solution {
 public:
  int maxDistance(vector<int>& position, int m) {
    sort(begin(position), end(position));

    int n = position.size();
    long long lo = 1;
    long long hi = position[n - 1] - position[0];

    while (lo < hi) {
      long long md = (lo + hi + 1) / 2;
      int cnt = 1;
      int p = position[0] + md;
      for (int i = 1; i < n && cnt < m; ++i) {
        if (position[i] >= p) {
          ++cnt;
          p = position[i] + md;
        }
      }

      if (cnt < m) {
        hi = md - 1;
      } else {
        lo = md;
      }
    }

    return lo;
  }
};
// 127 ms
// 61.36 MB
