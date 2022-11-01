class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    vector<vector<int>>& g = grid;
    int m = g.size();
    int n = g[0].size();

    vector<int> ans(n);
    for (int k = 0; k < n; ++k) {
      int cur = k;
      int i = 0;
      for (; i < m; ++i) {
        if ((g[i][cur] == 1 && (cur == n - 1 || g[i][cur + 1] == -1)) ||
            (g[i][cur] == -1 && (cur == 0 || g[i][cur - 1] == 1))) {
          break;
        }

        cur += g[i][cur];
      }

      ans[k] = i == m ? cur : -1;
    }

    return ans;
  }
};
// Runtime: 49 ms, faster than 63.64%
// Memory Usage: 13.1 MB, less than 95.61%
// 2022.11.1 at 奥盛大厦