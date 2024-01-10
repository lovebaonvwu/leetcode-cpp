class Solution {
 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    if (a == e) {
      if (d < min(b, f) || d > max(b, f)) {
        return 1;
      } else if (c != a) {
        return 1;
      }
    }

    if (b == f) {
      if (c < min(a, e) || c > max(a, e)) {
        return 1;
      } else if (d != b) {
        return 1;
      }
    }

    if (c + d == e + f) {
      if (a + b != c + d) {
        return 1;
      } else if (a < min(c, e) || a > max(c, e)) {
        return 1;
      }
    }

    if (c - d == e - f) {
      if (a - b != c - d) {
        return 1;
      } else if (a < min(c, e) || a > max(c, e)) {
        return 1;
      }
    }

    return 2;
  }
};
// 0ms
// 6.43MB