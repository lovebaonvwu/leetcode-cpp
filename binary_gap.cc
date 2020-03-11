class Solution {
 public:
  int binaryGap(int N) {
    int ans = 0;

    for (int i = 0, j = -1; N > 0; ++i, N >>= 1) {
      if (N & 1) {
        if (j >= 0) {
          ans = max(ans, i - j);
        }
        j = i;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.6 MB, less than 100.00%

class Solution {
 public:
  int binaryGap(int N) {
    vector<int> b;

    while (N > 0) {
      b.push_back(N % 2);

      N >>= 1;
    }

    int ans = 0;

    for (int i = 0, j = -1; i < b.size(); ++i) {
      if (b[i] == 1) {
        if (j >= 0) {
          ans = max(ans, i - j);
        }

        j = i;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.9 MB, less than 100.00%