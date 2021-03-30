class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    int w = 0, h = 0;

    for (auto& e : envelopes) {
      w = max(w, e[0]);
      h = max(h, e[1]);
    }

    vector<vector<int>> dp(w + 1, vector<int>(h + 1));

    for (auto& e : envelopes) {
      dp[e[0]][e[1]] = 1;
    }

    for (int i = 1; i < w + 1; ++i) {
      for (int j = 1; j < h + 1; ++j) {
        int max_cnt = 0;

        for (int k = 0; k < j; ++k) {
          max_cnt = max(max_cnt, dp[i - 1][k]);
        }

        for (int k = 0; k < i; ++k) {
          max_cnt = max(max_cnt, dp[k][j - 1]);
        }

        dp[i][j] = dp[i][j] + max_cnt;
      }
    }

    int ans = 0;

    for (int k = 0; k < w + 1; ++k) {
      ans = max(ans, dp[k][h]);
    }

    for (int k = 0; k < h + 1; ++k) {
      ans = max(ans, dp[w][k]);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<vector<int>>& e = envelopes;

    sort(e.begin(), e.end());

    int n = e.size();

    vector<int> dp(n + 1);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      dp[i] = 1;

      for (int j = i - 1; j >= 0; --j) {
        if (e[j][0] < e[i][0] && e[j][1] < e[i][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Runtime: 1172 ms, faster than 24.35%
// Memory Usage: 16.3 MB, less than 69.90%

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<vector<int>>& e = envelopes;

    sort(e.begin(), e.end(), [](auto& a, auto& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      } else {
        return a[0] < b[0];
      }
    });

    int n = e.size();

    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (e[i][1] > e[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Runtime: 916 ms, faster than 51.14%
// Memory Usage: 16.2 MB, less than 80.16%