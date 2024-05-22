class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>> cached(
        zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
    int mod = 1e9 + 7;

    function<int(int, int, int)> dfs = [&](int zero, int one, int p) -> int {
      if (zero == 0 && one == 0)
        return 1;
      if (cached[zero][one][p] != -1)
        return cached[zero][one][p];
      int ret = 0;
      if (p == 1) {
        for (int i = 1; i <= min(one, limit); ++i) {
          ret = (ret + dfs(zero, one - i, 0)) % mod;
        }
      } else {
        for (int i = 1; i <= min(zero, limit); ++i) {
          ret = (ret + dfs(zero - i, one, 1)) % mod;
        }
      }

      return cached[zero][one][p] = ret;
    };

    return (dfs(zero, one, 1) + dfs(zero, one, 0)) % mod;
  }
};
// 1207 ms
// 50.77 MB