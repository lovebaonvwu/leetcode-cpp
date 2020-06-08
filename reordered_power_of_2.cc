class Solution {
 public:
  bool reorderedPowerOf2(int N) {
    int templateN = transform(N);

    for (int i = 0; i < 32; ++i) {
      if (transform(1 << i) == templateN) {
        return true;
      }
    }

    return false;
  }

  int transform(int n) {
    int res = 0;
    for (; n; n /= 10) {
      res += pow(10, n % 10);
    }

    return res;
  }
};
// Runtime: 4 ms, faster than 54.71%
// Memory Usage: 6.2 MB, less than 46.90%

class Solution {
 public:
  bool reorderedPowerOf2(int N) {
    vector<int> tplN = transform(N);

    for (int i = 0; i < 31; ++i) {
      if (transform(1 << i) == tplN) {
        return true;
      }
    }

    return false;
  }

  vector<int> transform(int n) {
    vector<int> tpl(10, 0);
    for (; n; n /= 10) {
      ++tpl[n % 10];
    }

    return tpl;
  }
};
// Runtime: 4 ms, faster than 54.71%
// Memory Usage: 6.4 MB, less than 32.17%