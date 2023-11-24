class Solution {
 public:
  bool judgeSquareSum(int c) {
    int lo = 0;
    int hi = sqrt(c);

    while (lo <= hi) {
      int tmp = c - hi * hi;

      if (tmp == lo * lo) {
        return true;
      } else if (tmp > lo * lo) {
        ++lo;
      } else {
        --hi;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 79.11%
// Memory Usage: 8.1 MB, less than 100.00%

class Solution {
 public:
  bool judgeSquareSum(int c) {
    for (int i = 0; i <= sqrt(c); ++i) {
      int tmp = c - i * i;
      int j = sqrt(tmp);

      if (j * j == tmp) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 79.11%
// Memory Usage: 8.1 MB, less than 100.00%

class Solution {
 public:
  bool judgeSquareSum(int c) {
    unordered_set<long> st;

    for (long i = 0; i * i <= c; ++i) {
      st.insert(i * i);
    }

    for (long i = 0; i * i <= c; ++i) {
      if (st.count(c - i * i)) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 184 ms, faster than 12.49%
// Memory Usage: 62.9 MB, less than 8.33%