class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;

    int j = 0;
    for (int i = 0; i < pushed.size(); ++i) {
      stk.push(pushed[i]);

      while (!stk.empty() && stk.top() == popped[j]) {
        ++j;
        stk.pop();
      }
    }

    while (!stk.empty()) {
      if (stk.top() != popped[j]) {
        return false;
      } else {
        stk.pop();
        ++j;
      }
    }

    return j == popped.size();
  }
};
// Runtime: 16 ms, faster than 66.09%
// Memory Usage: 15.6 MB, less than 83.72%

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;

    for (int i = 0, j = 0; i < pushed.size(); ++i) {
      stk.push(pushed[i]);

      while (!stk.empty() && stk.top() == popped[j]) {
        ++j;
        stk.pop();
      }
    }

    return stk.empty();
  }
};
// Runtime: 12 ms, faster than 92.88%
// Memory Usage: 15.5 MB, less than 95.36%