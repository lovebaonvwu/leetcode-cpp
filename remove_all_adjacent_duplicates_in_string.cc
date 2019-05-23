class Solution {
 public:
  string removeDuplicates(string S) {
    string ans = "";

    for (char c : S) {
      if (!ans.empty() && ans.back() == c) {
        ans.pop_back();
      } else {
        ans.push_back(c);
      }
    }

    return ans;
  }
};  // 20ms

class Solution {
 public:
  string removeDuplicates(string S) {
    stack<char> stk;
    string ans = "";

    for (char c : S) {
      if (!stk.empty() && stk.top() == c) {
        stk.pop();
      } else {
        stk.push(c);
      }
    }

    while (!stk.empty()) {
      ans = stk.top() + ans;
      stk.pop();
    }

    return ans;
  }
};  // 340ms