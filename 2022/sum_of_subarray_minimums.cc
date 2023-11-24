class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    long long ans = accumulate(arr.begin(), arr.end(), 0L);
    int mod = 1e9 + 7;

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < n; ++i) {
      dp[i][0] = 0;
      dp[i][1] = arr[i];
    }

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        dp[i][len] = min(arr[i + len - 1], dp[i][len - 1]);
        ans = (ans + dp[i][len]) % mod;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2022.11.25 at 茗筑美嘉

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    long long ans = 0;
    int mod = 1e9 + 7;
    int n = arr.size();
    stack<int> stk;

    for (int i = 0; i <= n; ++i) {
      while (!stk.empty() && (i == n || arr[stk.top()] >= arr[i])) {
        int mid = stk.top();
        stk.pop();

        int left = stk.empty() ? -1 : stk.top();
        int right = i;
        long long count = (mid - left) * (right - mid);
        ans = (ans + count * arr[mid]) % mod;
      }

      stk.push(i);
    }

    return ans;
  }
};
// Runtime 175 ms
// Memory 39.3 MB
// 2022.11.25 at 茗筑美嘉