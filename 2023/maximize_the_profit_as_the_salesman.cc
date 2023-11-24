class Solution {
 public:
  int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    sort(offers.begin(), offers.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    int ans = 0;
    vector<int> dp(n);
    for (auto& offer : offers) {
      int start = offer[0];
      int end = offer[1];
      int profit = offer[2];

      if (start == 0) {
        dp[end] = max(dp[end], profit);
        ans = max(ans, dp[end]);
      }
      for (int i = 0; i < start; ++i) {
        dp[end] = max(dp[end], profit + dp[i]);
        ans = max(ans, dp[end]);
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    vector<vector<pair<int, int>>> cnt(n);
    vector<int> dp(n);

    for (auto& offer : offers) {
      int start = offer[0];
      int end = offer[1];
      int profit = offer[2];

      cnt[end].push_back({start, profit});
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      dp[i] = i > 0 ? dp[i - 1] : 0;
      for (auto& cur : cnt[i]) {
        int start = cur.first;
        int profit = cur.second;
        dp[i] = max(dp[i], (start > 0 ? dp[start - 1] : 0) + profit);
        ans = max(ans, dp[i]);
      }
    }

    return ans;
  }
};
// 371ms
// 135.25MB