class Solution {
 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    arr1.insert(arr1.begin(), 0);
    sort(arr2.begin(), arr2.end());

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = -1;

    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (arr1[i] > dp[i - 1][j]) {
          dp[i][j] = min(dp[i][j], arr1[i]);
        }

        if (j > 0) {
          auto it = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
          if (it != arr2.end()) {
            dp[i][j] = min(dp[i][j], *it);
          }
        }
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j <= m; ++j) {
      if (dp[m][j] != INT_MAX) {
        ans = min(ans, j);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// Runtime 344 ms
// Memory 36.6 MB