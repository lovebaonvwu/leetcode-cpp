class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    int l = 0, r = 0, u = 0;
    for (auto m : moves) {
      if (m == 'L') {
        ++l;
      } else if (m == 'R') {
        ++r;
      } else {
        ++u;
      }
    }

    return max(l, r) + u - min(l, r);
  }
};
// 0ms
// 6.39MB