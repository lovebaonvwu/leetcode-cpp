class Solution {
 public:
  int longestValidParentheses(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      stack<char> stk;

      for (int j = i; j < s.size(); ++j) {
        if (s[j] == ')' && stk.empty()) {
          break;
        } else if (s[j] == ')' && stk.top() == '(') {
          stk.pop();
        } else {
          stk.push(s[j]);
        }

        if (stk.empty()) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size();

    stack<int> stk;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        if (stk.empty()) {
          stk.push(i);
        } else {
          if (s[stk.top()] == '(') {
            stk.pop();
          } else {
            stk.push(i);
          }
        }
      }
    }

    if (stk.empty()) {
      return n;
    }

    int ans = 0;

    int i = stk.top(), j = n;

    while (!stk.empty()) {
      i = stk.top();
      stk.pop();
      ans = max(ans, j - i - 1);

      j = i;
    }

    ans = max(ans, j);

    return ans;
  }
};
// Runtime: 4 ms, faster than 80.90%
// Memory Usage: 7.3 MB, less than 48.61%

class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size();

    vector<int> dp(n + 1);

    int ans = 0;

    for (int i = 1; i < n; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = dp[i - 1] + 2;

          if (i > dp[i]) {
            dp[i] += dp[i - dp[i]];
          }

        } else {
          if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
            dp[i] = dp[i - 1] + 2;

            if (i > dp[i]) {
              dp[i] += dp[i - dp[i]];
            }
          }
        }
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 80.90%
// Memory Usage: 7.3 MB, less than 48.61%