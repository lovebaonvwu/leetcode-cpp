class Solution {
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  long long countVowels(string word) {
    int n = word.size();

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));

    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n - i; ++j) {
        dp[i][j] = dp[i - 1][j] + isVowel(word[j + i - 1]);

        ans += dp[i][j];
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

 public:
  long long countVowels(string word) {
    int n = word.size();
    long long ans = 0;

    for (long long i = 0; i < n; ++i) {
      if (isVowel(word[i])) {
        ans += (i + 1) * (n - i);
      }
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 91.25%
// Memory Usage: 11 MB, less than 89.28%
// 2021.12.12 at 茗筑美嘉