class Solution {
 public:
  string reverseParentheses(string s) {
    stack<int> stk;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(i);
      } else if (s[i] == ')') {
        int idx = stk.top();
        stk.pop();

        reverse(s.begin() + idx + 1, s.begin() + i);
      }
    }

    string ans;
    for (const auto& ch : s) {
      if (isalpha(ch)) {
        ans += ch;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  string reverseParentheses(string s) {
    stack<int> stk;
    string ans;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stk.push(ans.length());
      } else if (s[i] == ')') {
        int idx = stk.top();
        stk.pop();

        reverse(ans.begin() + idx, ans.end());
      } else {
        ans += s[i];
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 63.48%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  string reverseParentheses(string s) {
    string ans;

    deque<char> dq;

    for (const auto& ch : s) {
      if (ch != ')') {
        dq.push_back(ch);
        continue;
      }

      while (dq.back() != '(') {
        ans += dq.back();
        dq.pop_back();
      }

      dq.pop_back();

      for (const auto& a : ans) {
        dq.push_back(a);
      }

      ans = "";
    }

    while (!dq.empty()) {
      ans += dq.front();
      dq.pop_front();
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 63.48%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  string reverseParentheses(string s) {
    string ans;

    stack<char> stk;

    for (const auto& ch : s) {
      if (ch == ')') {
        while (stk.top() != '(') {
          ans += stk.top();
          stk.pop();
        }

        stk.pop();

        for (const auto& a : ans) {
          stk.push(a);
        }

        ans = "";
      } else {
        stk.push(ch);
      }
    }

    while (!stk.empty()) {
      ans += stk.top();
      stk.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 4 ms, faster than 63.48%
// Memory Usage: 8.7 MB, less than 100.00%