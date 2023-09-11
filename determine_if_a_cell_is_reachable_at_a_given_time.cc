class Solution {
 public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    if (sx == fx && sy == fy && t == 1) {
      return false;
    }

    if (min(abs(fx - sx), abs(fy - sy)) + max(abs(fx - sx), abs(fy - sy)) -
            min(abs(fx - sx), abs(fy - sy)) >
        t) {
      return false;
    }

    return true;
  }
};
// 2ms
// 6.12MB

class Solution {
 public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    if (sx == fx && sy == fy && t == 1) {
      return false;
    }

    if (max(abs(fx - sx), abs(fy - sy)) > t) {
      return false;
    }

    return true;
  }
};
// 2ms
// 6MB