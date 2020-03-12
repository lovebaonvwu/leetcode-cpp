class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    vector<int> dp(min(n, 10) + 1, 1);

    for (int i = 1; i <= min(n, 10); ++i) {
      dp[i] = dp[i - 1] * (i == 1 ? 9 : (9 - i + 2));
    }

    return accumulate(dp.begin(), dp.end(), 0);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.4 MB, less than 100.00%

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }

    int dp[n + 1];

    dp[0] = 1;
    dp[1] = 10;

    for (int i = 2; i <= n; ++i) {
      dp[i] = 9;

      for (int j = 1, k = 9; j < i; ++j, --k) {
        dp[i] *= k;
      }

      dp[i] += dp[i - 1];
    }

    return dp[n];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.3 MB, less than 100.00%

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    int cnt[10] = {0};

    int ans = 0;

    int total = pow(10, n);

    for (int i = 0; i < total; ++i) {
      memset(cnt, 0, sizeof(cnt));

      for (int x = i; x > 0; x /= 10) {
        ++cnt[x % 10];
      }

      if (all_of(cnt, cnt + 10, [](int a) { return a < 2; })) {
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded