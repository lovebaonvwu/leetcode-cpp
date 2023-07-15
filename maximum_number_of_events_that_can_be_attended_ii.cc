class Solution {
 public:
  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());

    int n = events.size();
    vector<vector<int>> dp(k + 1, vector<int>(n));

    int ans = 0;
    for (int j = 0; j < n; ++j) {
      dp[1][j] = events[j][2];
      ans = max(ans, dp[1][j]);
    }

    for (int i = 2; i <= k; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int p = 0; p < j; ++p) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j]);
          if (events[j][0] > events[p][1]) {
            dp[i][j] = max(dp[i][j], dp[i - 1][p] + events[j][2]);
          }
        }

        ans = max(ans, dp[i][j]);
      }
    }

    return ans;
  }
};
// TLE

class Solution {
  int upper_bound(const vector<vector<int>>& events, int target) {
    int lo = 0, hi = events.size();

    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (events[mid][0] <= target) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return lo;
  }

 public:
  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end());

    int n = events.size();
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int j = n - 1; j >= 0; --j) {
      for (int i = 1; i <= k; ++i) {
        int index = upper_bound(events, events[j][1]);
        dp[i][j] = max(dp[i][j + 1], dp[i - 1][index] + events[j][2]);
      }
    }

    return dp[k][0];
  }
};
// 348ms
// 57.61mb