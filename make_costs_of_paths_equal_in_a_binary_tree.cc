class Solution {
  int ans = 0;

 public:
  int minIncrements(int n, vector<int>& cost) {
    dfs(n, 1, cost);

    return ans;
  }

  int dfs(int n, int i, const vector<int>& cost) {
    if (i > n) {
      return 0;
    }

    int lsum = dfs(n, 2 * i, cost);
    int rsum = dfs(n, 2 * i + 1, cost);

    ans += abs(lsum - rsum);

    return max(lsum, rsum) + cost[i - 1];
  }
};
// Runtime 228 ms
// Memory 135 MB