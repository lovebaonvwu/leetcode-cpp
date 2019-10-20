class Solution {
 public:
  int balancedStringSplit(string s) {
    int ans = 0;
    int cnt = s[0] == 'L' ? -1 : 1;

    for (int i = 1; i < s.size(); ++i) {
      cnt = s[i] == 'L' ? cnt - 1 : cnt + 1;

      if (cnt == 0) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 57.84%
// Memory Usage: 8.3 MB, less than 100.00%

class Solution {
 public:
  int balancedStringSplit(string s) {
    stack<char> stk;

    int ans = 0;
    stk.push(s[0]);

    for (int i = 1; i < s.size(); ++i) {
      if (stk.empty() || s[i] == stk.top()) {
        stk.push(s[i]);
        continue;
      }

      stk.pop();

      if (stk.empty()) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 57.84%
// Memory Usage: 8.6 MB, less than 100.00%

class Solution {
 public:
  int balancedStringSplit(string s) {
    stack<char> stk;

    int ans = 0;
    for (const auto& ch : s) {
      if (stk.empty()) {
        stk.push(ch);
      } else {
        if (ch == 'L' && stk.top() == 'R' || ch == 'R' && stk.top() == 'L') {
          stk.pop();
          if (stk.empty()) {
            ++ans;
          }
        } else {
          stk.push(ch);
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 57.84%
// Memory Usage: 8.7 MB, less than 100.00%