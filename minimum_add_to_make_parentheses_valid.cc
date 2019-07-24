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