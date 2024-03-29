class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size();

    vector<long long> dp(n, 1);

    long long ans = dp[0];

    for (int i = 1; i < n; ++i) {
      if (prices[i - 1] - prices[i] == 1) {
        dp[i] += dp[i - 1];
      }

      ans += dp[i];
    }

    return ans;
  }
};
// Runtime: 136 ms, faster than 83.59%
// Memory Usage: 101.4 MB, less than 5.57%
// 2021.12.21 at 奥盛大厦

class Solution {
 public:
  long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size();

    long long ans = 1, cnt = 1;

    for (int i = 1; i < n; ++i) {
      if (prices[i - 1] - prices[i] == 1) {
        ++cnt;
      } else {
        cnt = 1;
      }

      ans += cnt;
    }

    return ans;
  }
};
// Runtime: 140 ms, faster than 80.33%
// Memory Usage: 93.2 MB, less than 41.40%
// 2021.12.21 at 奥盛大厦