class Solution {
 public:
  int rotatedDigits(int N) {
    int ans = 0;

    for (int i = 1; i <= N; ++i) {
      bool good = false;

      for (int n = i; n > 0; n /= 10) {
        int r = n % 10;

        if (r == 3 || r == 4 || r == 7) {
          good = false;
          break;
        }

        if (r == 2 || r == 5 || r == 6 || r == 9) {
          good = true;
        }
      }

      if (good) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 82.45%
// Memory Usage: 8.3 MB, less than 100.00%

class Solution {
 public:
  int rotatedDigits(int N) {
    int ans = 0;
    vector<int> must_have = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
    vector<int> cant_have = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0};

    for (int i = 1; i <= N; ++i) {
      int m = 0;
      int c = 0;

      for (int n = i; n > 0; n /= 10) {
        int r = n % 10;

        if (cant_have[r]) {
          ++c;
          break;
        }

        if (must_have[r]) {
          ++m;
        }
      }

      if (!c && m) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 82.45%
// Memory Usage: 8.3 MB, less than 80.00%

class Solution {
 public:
  int rotatedDigits(int N) {
    int ans = 0;

    for (int i = 1; i <= N; ++i) {
      int n = i;
      int x = 0;

      bool good = true;

      for (int j = 0, n = i; n > 0; n /= 10, ++j) {
        int r = n % 10;
        if (r == 3 || r == 4 || r == 7) {
          good = false;
          break;
        } else if (r == 2) {
          r = 5;
        } else if (r == 5) {
          r = 2;
        } else if (r == 6) {
          r = 9;
        } else if (r == 9) {
          r = 6;
        }

        x = x + r * pow(10, j);
      }

      if (good && x != i) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 82.45%
// Memory Usage: 8.3 MB, less than 100.00%