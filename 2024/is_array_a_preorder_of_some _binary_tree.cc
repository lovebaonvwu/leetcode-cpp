class Solution {
 public:
  bool isPreorder(vector<vector<int>>& nodes) {
    stack<int> stk;
    for (auto& n : nodes) {
      while (!stk.empty() && stk.top() != n[1]) {
        stk.pop();
      }

      if (stk.empty() && n[1] != -1) {
        return false;
      }

      stk.push(n[0]);
    }

    return true;
  }
};
// 283 ms
// 169.97 MB