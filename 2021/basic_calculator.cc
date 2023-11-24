class Solution {
 public:
  int calculate(string s) {
    stack<int> stk;
    int sign = 1;
    int ans = 0;
    int num = 0;

    for (auto c : s) {
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      } else if (c == '+') {
        ans += num * sign;
        num = 0;
        sign = 1;
      } else if (c == '-') {
        ans += num * sign;
        num = 0;
        sign = -1;
      } else if (c == '(') {
        stk.push(ans);
        stk.push(sign);
        ans = 0;
        sign = 1;
      } else if (c == ')') {
        ans += sign * num;
        num = 0;

        int outerSign = stk.top();
        stk.pop();
        int outerSum = stk.top();
        stk.pop();

        ans = outerSum + outerSign * ans;
      }
    }

    if (num) {
      ans += sign * num;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 98.70%
// Memory Usage: 8.2 MB, less than 46.32%
// 2021.9.11 at 茗筑美嘉