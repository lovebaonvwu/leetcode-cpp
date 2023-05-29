class Solution {
 public:
  int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);

    sort(cuts.begin(), cuts.end());
    int m = cuts.size();

    vector<vector<int>> memo(m, vector<int>(m));

    function<int(int, int)> dp = [&](int i, int j) {
      if (j - i <= 1) {
        return 0;
      }

      if (memo[i][j]) {
        return memo[i][j];
      }

      int cost = INT_MAX;
      for (int k = i + 1; k < j; ++k) {
        cost = min(cost, cuts[j] - cuts[i] + dp(i, k) + dp(k, j));
      }

      return memo[i][j] = cost;
    };

    return dp(0, m - 1);
  }
};
// Runtime 178 ms
// Memory 10.3 MB