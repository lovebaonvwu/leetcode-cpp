class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> cached(n, vector<int>(n + 1));
    function<int(int, int)> solve = [&](int s, int M) {
      if (s >= n) {
        return 0;
      }

      M = min(n, M);
      if (cached[s][M] > 0) {
        return cached[s][M];
      }

      if (s + 2 * M >= n) {
        return cached[s][M] = accumulate(begin(piles) + s, end(piles), 0);
      }

      int best = INT_MIN;
      int cur = 0;
      for (int i = 1; i <= 2 * M; ++i) {
        cur += piles[s + i - 1];
        best = max(best, cur - solve(s + i, max(M, i)));
      }

      return cached[s][M] = best;
    };

    int total = accumulate(begin(piles), end(piles), 0);
    return (total + solve(0, 1)) / 2;
  }
};
// Runtime: 37 ms, faster than 49.65%
// Memory Usage: 10.2 MB, less than 45.62%
// 2022.9.13 at 奥盛大厦