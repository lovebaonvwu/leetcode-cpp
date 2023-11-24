class Solution {
 public:
  int mirrorReflection(int p, int q) {
    int r = 1;
    int e = 1;

    while (q * r != p * e) {
      ++r;
      e = q * r / p;
    }

    if (r % 2 == 0) {
      return 2;
    } else if (e % 2 == 0) {
      return 0;
    } else {
      return 1;
    }
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 73.06%

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    int r = 1;
    int e = 1;

    while (q * r != p * e) {
      ++r;
      e = q * r / p;
    }

    return 1 - (e % 2 == 0) + (r % 2 == 0);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 15.03%

class Solution {
 public:
  int mirrorReflection(int p, int q) {
    int r = 1;
    int e = 1;

    while (q * r != p * e) {
      ++r;
      e = q * r / p;
    }

    return 1 - (r & 1) + (e & 1);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 15.03%