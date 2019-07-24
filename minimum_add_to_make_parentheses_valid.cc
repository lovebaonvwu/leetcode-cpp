class Solution {
 public:
  int minAddToMakeValid(string S) {
    stack<char> stk;

    for (auto& c : S) {
      if (!stk.empty() && (stk.top() == '(' && c == ')')) {
        stk.pop();
      } else {
        stk.push(c);
      }
    }

    return stk.size();
  }
};  // 0ms

class Solution {
 public:
  int minAddToMakeValid(string S) {
    int left = 0;
    int right = 0;

    for (auto& c : S) {
      if (c == '(') {
        ++left;
      } else if (left > 0) {
        --left;
      } else {
        ++right;
      }
    }

    return left + right;
  }
};  // 4ms
