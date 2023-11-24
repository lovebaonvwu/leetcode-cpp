class Solution {
 public:
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> p(N);

    for (auto& path : paths) {
      p[path[0] - 1].push_back(path[1] - 1);
      p[path[1] - 1].push_back(path[0] - 1);
    }

    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      int used[5] = {};
      for (auto neighbor : p[i]) {
        used[ans[neighbor]] = true;
      }

      for (int fl = 1; fl <= 4; ++fl) {
        if (!used[fl]) {
          ans[i] = fl;
        }
      }
    }

    return ans;
  }
};
// Runtime: 228 ms, faster than 61.30%
// Memory Usage: 40 MB, less than 100.00%