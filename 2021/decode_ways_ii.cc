class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    s = '#' + s;
    int mod = 1e9 + 7;

    vector<long> dp(n + 1);

    dp[0] = 1;
    if (s[1] == '*') {
      dp[1] = 9;
    } else if (s[1] == '0') {
      dp[1] = 0;
    } else {
      dp[1] = 1;
    }

    for (int i = 2; i <= n; ++i) {
      if (isdigit(s[i])) {
        if (s[i] != '0') {
          dp[i] += dp[i - 1];
        }

        if (s[i - 1] == '1') {
          dp[i] += dp[i - 2];
        } else if (s[i - 1] == '2') {
          if (s[i] < '7') {
            dp[i] += dp[i - 2];
          }
        } else if (s[i - 1] == '*') {
          dp[i] += dp[i - 2];
          if (s[i] < '7') {
            dp[i] += dp[i - 2];
          }
        }
      } else {
        dp[i] += dp[i - 1] * 9;

        if (s[i - 1] == '1') {
          dp[i] += dp[i - 2] * 9;
        } else if (s[i - 1] == '2') {
          dp[i] += dp[i - 2] * 6;
        } else if (s[i - 1] == '*') {
          dp[i] += dp[i - 2] * 15;
        }
      }

      dp[i] %= mod;
    }

    return dp[n];
  }
};
// Runtime: 60 ms, faster than 32.74%
// Memory Usage: 23 MB, less than 17.44%
// 2021.7.10 at 茗筑美嘉