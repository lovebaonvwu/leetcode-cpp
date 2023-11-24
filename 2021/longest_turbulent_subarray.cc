class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();

    vector<pair<int, int>> dp(n, pair<int, int>(1, 1));

    int ans = 1;

    for (int k = 0; k < n - 1; ++k) {
      if (k % 2 == 0) {
        if (arr[k] > arr[k + 1]) {
          dp[k + 1].first = dp[k].first + 1;
        } else if (arr[k] < arr[k + 1]) {
          dp[k + 1].second = dp[k].second + 1;
        }
      } else {
        if (arr[k] < arr[k + 1]) {
          dp[k + 1].first = dp[k].first + 1;
        } else if (arr[k] > arr[k + 1]) {
          dp[k + 1].second = dp[k].second + 1;
        }
      }

      ans = max(ans, max(dp[k + 1].first, dp[k + 1].second));
    }

    return ans;
  }
};
// Runtime: 80 ms, faster than 41.16%
// Memory Usage: 43.4 MB, less than 18.92%
// 2021.9.15 at 奥盛大厦

class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();

    vector<pair<int, int>> dp(n, pair<int, int>(1, 1));

    int ans = 1;

    for (int k = 0; k < n - 1; ++k) {
      if (arr[k] < arr[k + 1]) {
        dp[k + 1].first = dp[k].second + 1;
      } else if (arr[k] > arr[k + 1]) {
        dp[k + 1].second = dp[k].first + 1;
      }

      ans = max(ans, max(dp[k + 1].first, dp[k + 1].second));
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 32.06%
// Memory Usage: 43.6 MB, less than 18.10%
// 2021.9.15 at 奥盛大厦