class Solution {
  vector<vector<int>> memo;

 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    const int n = piles.size();
    memo = vector<vector<int>>(1000, vector<int>(2000));

    return dfs(piles, 0, k);
  }

  int dfs(const vector<vector<int>>& piles, int n, int k) {
    if (k == 0 || n >= piles.size()) {
      return 0;
    }

    if (memo[n][k] > 0) {
      return memo[n][k];
    }

    int ans = 0;

    for (int i = min(k, (int)piles[n].size()); i >= 0; --i) {
      int sum = 0;
      for (int j = 0; j < i; ++j) {
        sum += piles[n][j];
      }

      ans = max(ans, sum + dfs(piles, n + 1, k - i));
    }

    return memo[n][k] = ans;
  }
};
// Time Limit Exceeded

class Solution {
  vector<vector<int>> memo;

 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    const int n = piles.size();
    memo = vector<vector<int>>(n + 1, vector<int>(k + 1));

    return dfs(piles, 0, k);
  }

  int dfs(const vector<vector<int>>& piles, int n, int k) {
    if (k == 0 || n == piles.size()) {
      return 0;
    }

    if (memo[n][k] > 0) {
      return memo[n][k];
    }

    int ans = dfs(piles, n + 1, k);

    int sum = 0;
    for (int i = 0; i < k && i < piles[n].size(); ++i) {
      sum += piles[n][i];

      ans = max(ans, sum + dfs(piles, n + 1, k - i - 1));
    }

    return memo[n][k] = ans;
  }
};
// Runtime: 332 ms, faster than 66.29%
// Memory Usage: 18.2 MB, less than 54.42%
// 2022.4.3 at 茗筑美嘉