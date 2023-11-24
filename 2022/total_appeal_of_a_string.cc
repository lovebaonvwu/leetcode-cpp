class Solution {
 public:
  long long appealSum(string s) {
    int n = s.size();

    vector<vector<long long>> dp(n, vector<long long>(n));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    for (int j = 0; j < n; ++j) {
      dp[j][j] = 1;
    }

    for (int i = 0; i < n; ++i) {
      int cnt[26] = {0};
      ++cnt[s[i] - 'a'];

      for (int j = i + 1; j < n; ++j) {
        if (cnt[s[j] - 'a']) {
          dp[i][j] = dp[i][j - 1];
        } else {
          ++cnt[s[j] - 'a'];
          dp[i][j] = dp[i][j - 1] + 1;
        }
      }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ans += dp[i][j];
      }
    }

    return ans;
  }
};
// Memory Limit Exceeded

class Solution {
 public:
  long long appealSum(string s) {
    int n = s.size();

    vector<long long> dp(n);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int cnt[26] = {0};
      ++cnt[s[i] - 'a'];
      dp[i] = 1;

      for (int j = i + 1; j < n; ++j) {
        if (cnt[s[j] - 'a']) {
          dp[j] = dp[j - 1];
        } else {
          ++cnt[s[j] - 'a'];
          dp[j] = dp[j - 1] + 1;
        }
      }

      for (int k = i; k < n; ++k) {
        ans += dp[k];
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long appealSum(string s) {
    int n = s.size();

    vector<int> last(26, -1);

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int j = last[s[i] - 'a'];

      ans += (long long)(i - j) * (n - i);
      last[s[i] - 'a'] = i;
    }

    return ans;
  }
};
// Runtime: 34 ms, faster than 79.98%
// Memory Usage: 10.6 MB, less than 79.36%
// 2022.5.6 at 奥盛大厦