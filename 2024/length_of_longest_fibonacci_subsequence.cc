class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    unordered_map<int, int> mp;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      mp[arr[i]] = i;
    }

    vector<vector<int>> dp(n, vector<int>(n, 1));

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] - arr[j] < arr[j] && mp.find(arr[i] - arr[j]) != mp.end()) {
          int k = mp[arr[i] - arr[j]];
          dp[i][j] = max(dp[i][j], dp[j][k] + 1);
        }

        ans = max(ans, dp[i][j] + 1);
      }
    }

    return ans >= 3 ? ans : 0;
  }
};
// 302 ms
// 146.26 MB