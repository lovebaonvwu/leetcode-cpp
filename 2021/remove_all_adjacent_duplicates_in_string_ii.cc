class Solution {
 public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> stk;

    stk.push({s[0], 1});

    for (int i = 1; i < s.size(); ++i) {
      if (!stk.empty() && s[i] == stk.top().first) {
        stk.top().second++;
      } else {
        stk.push({s[i], 1});
      }

      if (stk.top().second == k) {
        stk.pop();
      }
    }

    string ans;

    while (!stk.empty()) {
      auto p = stk.top();
      stk.pop();

      ans = string(p.second, p.first) + ans;
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 65.65%
// Memory Usage: 132.2 MB, less than 100.00%

class Solution {
 public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> stk;

    stk.push({s[0], 1});

    for (int i = 1; i < s.size(); ++i) {
      if (!stk.empty() && s[i] == stk.top().first) {
        stk.top().second++;
      } else {
        stk.push({s[i], 1});
      }

      if (stk.top().second == k) {
        stk.pop();
      }
    }

    string ans;

    while (!stk.empty()) {
      auto p = stk.top();
      stk.pop();

      while (p.second-- > 0) {
        ans = p.first + ans;
      }
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 29.54%
// Memory Usage: 136.9 MB, less than 100.00%