class Solution {
 public:
  bool isValid(string S) {
    stack<char> stk;

    for (auto c : S) {
      if (c == 'a') {
        stk.push(c);
      } else if (c == 'b' && !stk.empty() && stk.top() == 'a') {
        stk.push(c);
      } else if (c == 'c' && !stk.empty() && stk.top() == 'b') {
        stk.pop();
        stk.pop();
      }
    }

    return stk.empty();
  }
};
// Runtime: 16 ms, faster than 65.30%
// Memory Usage: 8.3 MB, less than 90.30%

class Solution {
 public:
  bool isValid(string S) {
    vector<char> stk;

    for (auto c : S) {
      if (c == 'c') {
        int n = stk.size();
        if (n >= 2 && stk[n - 2] == 'a' && stk[n - 1] == 'b') {
          stk.pop_back();
          stk.pop_back();
        } else {
          stk.push_back(c);
        }
      } else {
        stk.push_back(c);
      }
    }

    return stk.empty();
  }
};
// Runtime: 12 ms, faster than 89.37%
// Memory Usage: 8.7 MB, less than 56.34%