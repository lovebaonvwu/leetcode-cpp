class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size();

    vector<vector<int>> cached(n, vector<int>(key.size(), -1));

    function<int(int, int)> dfs = [&](int cur, int k) -> int {
      if (k == key.size()) {
        return 0;
      }

      if (cached[cur][k] != -1) {
        return cached[cur][k];
      }

      int ret = INT_MAX / 2;
      for (int i = 0; i < n; ++i) {
        if (ring[(cur + i) % n] == key[k]) {
          ret = min(ret, 1 + i + dfs((cur + i) % n, k + 1));
        }
      }

      for (int i = 0; i < n; ++i) {
        if (ring[(cur - i + n) % n] == key[k]) {
          ret = min(ret, 1 + i + dfs((cur - i + n) % n, k + 1));
        }
      }

      return cached[cur][k] = ret;
    };

    return dfs(0, 0);
  }
};
// 48 ms
// 14.74 MB