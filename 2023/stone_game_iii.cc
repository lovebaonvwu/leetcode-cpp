class Solution {
 public:
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();

    vector<int> memo(n, INT_MIN);

    function<int(int)> dp = [&](int i) {
      if (i >= n) {
        return 0;
      }

      if (memo[i] != INT_MIN) {
        return memo[i];
      }

      int score = 0;
      for (int k = 0; k < 3 && i + k < n; ++k) {
        score += stoneValue[i + k];

        memo[i] = max(memo[i], score - dp(i + k + 1));
      }

      return memo[i];
    };

    int score = dp(0);

    return score > 0 ? "Alice" : score < 0 ? "Bob" : "Tie";
  }
};
// Runtime 420 ms
// Memory 149.7 MB