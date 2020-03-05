class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;

    for (int i = left; i <= right; ++i) {
      int n = i;

      while (n > 0) {
        int r = n % 10;
        if (!r || i % r) {
          break;
        }

        n /= 10;
      }

      if (!n) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.6 MB, less than 100.00%

class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;

    for (int i = left; i <= right; ++i) {
      int n = i;

      bool good = true;
      while (n > 0) {
        int r = n % 10;
        if (!r || i % r) {
          good = false;
          break;
        }

        n /= 10;
      }

      if (good) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 69.85%
// Memory Usage: 7.5 MB, less than 100.00%