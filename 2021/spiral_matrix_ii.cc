class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));

    int i = 1;
    int r0 = 0;
    int r1 = n;
    int c0 = 0;
    int c1 = n;

    enum direction { right, down, left, up };

    direction d = right;

    while (i <= n * n) {
      switch (d) {
        case right:
          for (int j = c0; j < c1; j++) {
            ans[r0][j] = i++;
          }
          r0++;
          d = down;
          break;
        case down:
          for (int j = r0; j < r1; j++) {
            ans[j][c1 - 1] = i++;
          }
          c1--;
          d = left;
          break;
        case left:
          for (int j = c1 - 1; j >= c0; j--) {
            ans[r1 - 1][j] = i++;
          }
          r1--;
          d = up;
          break;
        case up:
          for (int j = r1 - 1; j >= r0; j--) {
            ans[j][c0] = i++;
          }
          c0++;
          d = right;
          break;
      }
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));

    int i = 1;
    int r0 = 0;
    int r1 = n - 1;
    int c0 = 0;
    int c1 = n - 1;
    int cnt = n * n;

    enum direction { right, down, left, up };

    direction d = right;

    while (i <= cnt) {
      switch (d) {
        case right:
          for (int j = c0; j <= c1; j++) {
            ans[r0][j] = i++;
          }
          r0++;
          d = down;
          break;
        case down:
          for (int j = r0; j <= r1; j++) {
            ans[j][c1] = i++;
          }
          c1--;
          d = left;
          break;
        case left:
          for (int j = c1; j >= c0; j--) {
            ans[r1][j] = i++;
          }
          r1--;
          d = up;
          break;
        case up:
          for (int j = r1; j >= r0; j--) {
            ans[j][c0] = i++;
          }
          c0++;
          d = right;
          break;
      }
    }

    return ans;
  }
};  // 4ms