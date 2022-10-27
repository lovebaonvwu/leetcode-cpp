class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();

    vector<int> dp(n, 1);

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] - arr[j] == difference) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int ans = 1;
    unordered_map<int, int> mp;

    for (auto n : arr) {
      if (mp.find(n - difference) != mp.end()) {
        mp[n] = mp[n - difference] + 1;
      } else {
        mp[n] = 1;
      }

      ans = max(ans, mp[n]);
    }

    return ans;
  }
};
// Runtime: 184 ms, faster than 82.57%
// Memory Usage: 55 MB, less than 64.73%
// 2022.10.27 at 奥盛大厦