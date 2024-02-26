class Solution {
 public:
  int mostExpensiveItem(int primeOne, int primeTwo) {
    int n = primeOne * primeTwo;
    vector<int> dp(n + 1);

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
      if (i % primeOne == 0 || i % primeTwo == 0) {
        dp[i] = true;
      }

      if (i >= primeOne && dp[i - primeOne]) {
        dp[i] = true;
      }

      if (i >= primeTwo && dp[i - primeTwo]) {
        dp[i] = true;
      }

      if (dp[i] == false) {
        ans = i;
      }
    }

    return ans;
  }
};
// 64 ms
// 47.11 MB