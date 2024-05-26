class Solution {
 public:
  int checkRecord(int n) {
    int mod = 1e9 + 7;

    vector<vector<vector<int>>> cached(
        n, vector<vector<int>>(3, vector<int>(2, -1)));

    function<int(int, int, int)> dfs = [&](int i, int L, int A) -> int {
      if (i == n)
        return 1;

      if (cached[i][L][A] != -1)
        return cached[i][L][A];

      int ret = 0;
      ret = (ret + dfs(i + 1, 0, A)) % mod;
      if (L < 2)
        ret = (ret + dfs(i + 1, L + 1, A)) % mod;
      if (A < 1)
        ret = (ret + dfs(i + 1, 0, A + 1)) % mod;

      return cached[i][L][A] = ret;
    };

    return dfs(0, 0, 0);
  }
};
// Time Limit Exceeded