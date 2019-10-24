class Solution {
 public:
  bool stoneGame(vector<int>& piles) { return true; }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.4 MB, less than 100.00%

class Solution {
  int dp[501][501];

 public:
  bool stoneGame(vector<int>& piles) {
    memset(dp, -1, sizeof(dp));

    int alex = process(0, piles.size() - 1, piles);

    int sum = accumulate(piles.begin(), piles.end(), 0);

    return alex > (sum - alex);
  }

  int process(int l, int r, vector<int>& p) {
    if (l > r) {
      return 0;
    }

    if (dp[l][r] > -1) {
      return dp[l][r];
    }

    int left = p[l] + max(process(l + 2, r, p), process(l + 1, r - 1, p));
    int right = p[r] + max(process(l, r - 2, p), process(l + 1, r - 1, p));

    return dp[l][r] = max(left, right);
  }
};
// Runtime: 28 ms, faster than 20.03%
// Memory Usage: 10 MB, less than 20.00%