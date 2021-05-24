class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();

    vector<bool> dp(n);

    dp[0] = true;

    for (int i = 1; i < n; ++i) {
      if (s[i] == '0') {
        for (int j = max(0, i - maxJump); j <= i - minJump; ++j) {
          if (dp[j]) {
            dp[i] = true;
            break;
          }
        }
      }
    }

    return dp[n - 1];
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    queue<int> q;
    q.push(0);

    int furthest = 0;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (cur == s.size() - 1) {
        return true;
      }

      for (int i = max(cur + minJump, furthest + 1);
           i <= min(cur + maxJump, (int)s.size() - 1); ++i) {
        if (s[i] == '0') {
          q.push(i);
        }

        furthest = max(furthest, i);
      }
    }

    return false;
  }
};
// Runtime: 56 ms, faster than 12.50%
// Memory Usage: 19.8 MB, less than 25.00%

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();

    vector<bool> dp(n);
    dp[0] = true;

    int cnt = 0;
    for (int i = minJump; i < n; ++i) {
      cnt += dp[i - minJump];

      if (i > maxJump) {
        cnt -= dp[i - maxJump - 1];
      }

      dp[i] = cnt > 0 && s[i] == '0';
    }

    return dp[n - 1];
  }
};
// Runtime: 56 ms, faster than 12.50%
// Memory Usage: 16.1 MB, less than 62.50%