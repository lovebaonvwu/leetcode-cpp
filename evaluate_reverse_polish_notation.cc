class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    unordered_set<string> st{"+", "-", "*", "/"};
    stack<int> stk;

    for (auto& t : tokens) {
      if (st.count(t) == 0) {
        stk.push(stoi(t));
      } else {
        int t1 = stk.top();
        stk.pop();

        int t2 = stk.top();
        stk.pop();

        if (t == "+") {
          stk.push(t2 + t1);
        } else if (t == "-") {
          stk.push(t2 - t1);
        } else if (t == "*") {
          stk.push(t2 * t1);
        } else {
          stk.push(t2 / t1);
        }
      }
    }

    return stk.top();
  }
};  // 12ms

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
};  // 12ms