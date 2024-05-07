class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    long long lo = 1, hi = 1000000;

    while (lo < hi) {
      long long md = (lo + hi + 1) / 2;
      long long sum = 0;
      for (int i = 1; i <= md; ++i) {
        for (int j = 1; x * j - 1 < 31; ++j) {
          sum += (i & (1 << (x * j - 1))) > 0;
        }
      }

      if (sum <= k) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }

    return lo;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long findMaximumNumber(long long k, int x) {
    function<long long(long long)> count = [&](long long md) -> long long {
      long long ret = 0;

      vector<int> bits;
      long long t = md;
      while (t > 0) {
        bits.push_back(t % 2);
        t /= 2;
      }

      for (long long i = x - 1; (1LL << i) <= md; i += x) {
        if (bits[i] == 0) {
          long long major = 0;
          for (int j = bits.size() - 1; j > i; --j) {
            major = major * 2 + bits[j];
          }

          ret += major * pow(2, i);
        } else {
          long long major = 0;
          for (int j = bits.size() - 1; j > i; --j) {
            major = major * 2 + bits[j];
          }

          ret += major * pow(2, i);

          long long minor = 0;
          for (int j = i - 1; j >= 0; --j) {
            minor = minor * 2 + bits[j];
          }
          ret += minor + 1;
        }
      }

      return ret;
    };

    long long lo = 1, hi = 1e15;

    while (lo < hi) {
      long long md = (lo + hi + 1) / 2;
      long long sum = count(md);

      if (sum <= k) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }

    return lo;
  }
};
// 91 ms
// 39.39 MB