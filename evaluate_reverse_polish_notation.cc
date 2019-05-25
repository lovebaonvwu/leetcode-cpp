class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    int t1, t2;

    for (auto& token : tokens) {
      if (token == "+") {
        t1 = stk.top();
        stk.pop();
        t2 = stk.top();
        stk.pop();
        stk.push(t1 + t2);
      } else if (token == "-") {
        t1 = stk.top();
        stk.pop();
        t2 = stk.top();
        stk.pop();
        stk.push(t2 - t1);
      } else if (token == "*") {
        t1 = stk.top();
        stk.pop();
        t2 = stk.top();
        stk.pop();
        stk.push(t1 * t2);
      } else if (token == "/") {
        t1 = stk.top();
        stk.pop();
        t2 = stk.top();
        stk.pop();
        stk.push(t2 / t1);
      } else {
        stk.push(stoi(token));
      }
    }

    return stk.top();
  }
};