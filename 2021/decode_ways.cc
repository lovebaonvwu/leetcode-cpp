class Solution {
  int ans;

 public:
  int numDecodings(string s) {
    dfs(s, 0);

    return ans;
  }

  void dfs(string s, int start) {
    if (start > s.size()) {
      return;
    }

    if (start == s.size()) {
      ++ans;
      return;
    }

    for (int i = 1; i <= 2; ++i) {
      auto val = stoi(s.substr(start, i));

      if (val < 1 || val > 26) {
        return;
      }

      dfs(s, start + i);
    }
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int numDecodings(string s) {
    vector<int> mem(s.size() + 1, -1);

    return dfs(s, 0, mem);
  }

  int dfs(string s, int p, vector<int>& mem) {
    if (p == s.size()) {
      return mem[p] = 1;
    }

    if (mem[p] != -1) {
      return mem[p];
    }

    int cnt = 0;
    if (s[p] != '0') {
      cnt += dfs(s, p + 1, mem);
    }

    if (p + 1 < s.size() && (s[p] == '1' || s[p] == '2' && s[p + 1] <= '6')) {
      cnt += dfs(s, p + 2, mem);
    }

    return mem[p] = cnt;
  }
};
// Runtime: 4 ms, faster than 34.90%
// Memory Usage: 7.9 MB, less than 14.10%

class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();

    vector<int> dp(n + 1);

    dp[n] = 1;
    dp[n - 1] = s[n - 1] == '0' ? 0 : 1;

    for (int i = n - 2; i >= 0; --i) {
      if (s[i] == '0') {
        dp[i] = 0;
        continue;
      }

      dp[i] += dp[i + 1];

      if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
        dp[i] += dp[i + 2];
      }
    }

    return dp[0];
  }
};
// Runtime: 4 ms, faster than 34.90%
// Memory Usage: 6.6 MB, less than 51.80%