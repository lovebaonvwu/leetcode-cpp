class Solution {
 public:
  int longestMountain(vector<int>& A) {
    int n = A.size();

    vector<int> up(n, 0);
    vector<int> down(n, 0);

    int ans = 0;

    for (int i = n - 2; i >= 0; --i) {
      if (A[i] > A[i + 1]) {
        down[i] = down[i + 1] + 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (i > 0 && A[i] > A[i - 1]) {
        up[i] = up[i - 1] + 1;
      }

      if (up[i] && down[i]) {
        ans = max(ans, up[i] + down[i] + 1);
      }
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 57.65%
// Memory Usage: 10.9 MB, less than 14.29%

class Solution {
 public:
  int longestMountain(vector<int>& A) {
    if (A.size() < 3) {
      return 0;
    }

    int ans = 0;
    int cnt = 0;
    int up = 0;

    for (int i = 1; i < A.size(); ++i) {
      if (A[i] == A[i - 1]) {
        if (up < 0) {
          ans = max(ans, cnt);
        }

        cnt = 0;
        up = 0;
      } else if (A[i] > A[i - 1]) {
        if (up == 0) {
          cnt = 2;
        } else if (up < 0) {
          ans = max(ans, cnt);
          cnt = 2;
        } else {
          ++cnt;
        }

        up = 1;
      } else {
        if (up == 0) {
        } else if (up > 0) {
          up = -1;
          ++cnt;
        } else {
          ++cnt;
        }
      }
    }

    return up < 0 ? max(ans, cnt) : ans;
  }
};
// Runtime: 24 ms, faster than 57.65%
// Memory Usage: 10 MB, less than 28.57%

class Solution {
 public:
  int longestMountain(vector<int>& A) {
    int ans = 0;
    int up = 0;
    int down = 0;

    for (int i = 1; i < A.size(); ++i) {
      if (down && A[i] > A[i - 1] || A[i] == A[i - 1]) {
        down = 0;
        up = 0;
      }

      up += A[i] > A[i - 1];
      down += A[i] < A[i - 1];

      if (up && down) {
        ans = max(ans, up + down + 1);
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 12.10%
// Memory Usage: 10.1 MB, less than 14.29%